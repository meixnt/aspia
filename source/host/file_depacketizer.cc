//
// Aspia Project
// Copyright (C) 2018 Dmitry Chapyshev <dmitry@aspia.ru>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <https://www.gnu.org/licenses/>.
//

#include "host/file_depacketizer.h"

#include <QDebug>

namespace aspia {

FileDepacketizer::FileDepacketizer(const std::filesystem::path& file_path,
                                   std::ofstream&& file_stream)
    : file_path_(file_path),
      file_stream_(std::move(file_stream))
{
    // Nothing
}

// static
std::unique_ptr<FileDepacketizer> FileDepacketizer::create(
    const std::filesystem::path& file_path, bool overwrite)
{
    std::ofstream::openmode mode = std::ofstream::binary;

    if (overwrite)
        mode |= std::ofstream::trunc;

    std::ofstream file_stream;

    file_stream.open(file_path, mode);
    if (!file_stream.is_open())
        return nullptr;

    return std::unique_ptr<FileDepacketizer>(
        new FileDepacketizer(file_path, std::move(file_stream)));
}

bool FileDepacketizer::writeNextPacket(const proto::file_transfer::Packet& packet)
{
    Q_ASSERT(file_stream_.is_open());

    const size_t packet_size = packet.data().size();
    if (!packet_size)
    {
        if (packet.flags() & proto::file_transfer::Packet::LAST_PACKET)
        {
            file_stream_.close();

            // The transfer of files was canceled. Delete the file.
            std::error_code ignored_error;
            std::filesystem::remove(file_path_, ignored_error);
            return true;
        }

        qWarning("Wrong packet size");
        return false;
    }

    // The first packet must have the full file size.
    if (packet.flags() & proto::file_transfer::Packet::FIRST_PACKET)
    {
        file_size_ = packet.file_size();
        left_size_ = file_size_;
    }

    file_stream_.seekp(file_size_ - left_size_);
    file_stream_.write(packet.data().data(), packet_size);
    if (file_stream_.fail())
    {
        qDebug("Unable to write file");
        return false;
    }

    left_size_ -= packet_size;

    if (packet.flags() & proto::file_transfer::Packet::LAST_PACKET)
    {
        file_size_ = 0;
        file_stream_.close();
    }

    return true;
}

} // namespace aspia
