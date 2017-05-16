// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: auth_session_message.proto

#ifndef PROTOBUF_auth_5fsession_5fmessage_2eproto__INCLUDED
#define PROTOBUF_auth_5fsession_5fmessage_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3003000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3003001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_util.h>
// @@protoc_insertion_point(includes)
namespace aspia {
namespace proto {
}  // namespace proto
}  // namespace aspia

namespace aspia {
namespace proto {

namespace protobuf_auth_5fsession_5fmessage_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[];
  static const ::google::protobuf::uint32 offsets[];
  static void InitDefaultsImpl();
  static void Shutdown();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_auth_5fsession_5fmessage_2eproto

enum AuthMethod {
  AUTH_METHOD_UNKNOWN = 0,
  AUTH_METHOD_BASIC = 1,
  AuthMethod_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  AuthMethod_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool AuthMethod_IsValid(int value);
const AuthMethod AuthMethod_MIN = AUTH_METHOD_UNKNOWN;
const AuthMethod AuthMethod_MAX = AUTH_METHOD_BASIC;
const int AuthMethod_ARRAYSIZE = AuthMethod_MAX + 1;

enum AuthStatus {
  AUTH_STATUS_UNKNOWN = 0,
  AUTH_STATUS_SUCCESS = 1,
  AUTH_STATUS_NOT_SUPPORTED_METHOD = 2,
  AUTH_STATUS_SESSION_TYPE_NOT_ALLOWED = 3,
  AUTH_STATUS_BAD_USERNAME_OR_PASSWORD = 4,
  AuthStatus_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  AuthStatus_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool AuthStatus_IsValid(int value);
const AuthStatus AuthStatus_MIN = AUTH_STATUS_UNKNOWN;
const AuthStatus AuthStatus_MAX = AUTH_STATUS_BAD_USERNAME_OR_PASSWORD;
const int AuthStatus_ARRAYSIZE = AuthStatus_MAX + 1;

enum SessionType {
  SESSION_TYPE_UNKNOWN = 0,
  SESSION_TYPE_DESKTOP_MANAGE = 1,
  SESSION_TYPE_DESKTOP_VIEW = 2,
  SESSION_TYPE_POWER_MANAGE = 4,
  SESSION_TYPE_FILE_TRANSFER = 8,
  SESSION_TYPE_SYSTEM_INFO = 16,
  SessionType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  SessionType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool SessionType_IsValid(int value);
const SessionType SessionType_MIN = SESSION_TYPE_UNKNOWN;
const SessionType SessionType_MAX = SESSION_TYPE_SYSTEM_INFO;
const int SessionType_ARRAYSIZE = SessionType_MAX + 1;

// ===================================================================


// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)


}  // namespace proto
}  // namespace aspia

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::aspia::proto::AuthMethod> : ::google::protobuf::internal::true_type {};
template <> struct is_proto_enum< ::aspia::proto::AuthStatus> : ::google::protobuf::internal::true_type {};
template <> struct is_proto_enum< ::aspia::proto::SessionType> : ::google::protobuf::internal::true_type {};

}  // namespace protobuf
}  // namespace google
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_auth_5fsession_5fmessage_2eproto__INCLUDED
