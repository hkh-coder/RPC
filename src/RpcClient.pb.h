// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: RpcClient.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_RpcClient_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_RpcClient_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3011000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3011000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_RpcClient_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_RpcClient_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_RpcClient_2eproto;
class ClientData_Header;
class ClientData_HeaderDefaultTypeInternal;
extern ClientData_HeaderDefaultTypeInternal _ClientData_Header_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::ClientData_Header* Arena::CreateMaybeMessage<::ClientData_Header>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class ClientData_Header :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:ClientData_Header) */ {
 public:
  ClientData_Header();
  virtual ~ClientData_Header();

  ClientData_Header(const ClientData_Header& from);
  ClientData_Header(ClientData_Header&& from) noexcept
    : ClientData_Header() {
    *this = ::std::move(from);
  }

  inline ClientData_Header& operator=(const ClientData_Header& from) {
    CopyFrom(from);
    return *this;
  }
  inline ClientData_Header& operator=(ClientData_Header&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const ClientData_Header& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ClientData_Header* internal_default_instance() {
    return reinterpret_cast<const ClientData_Header*>(
               &_ClientData_Header_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(ClientData_Header& a, ClientData_Header& b) {
    a.Swap(&b);
  }
  inline void Swap(ClientData_Header* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline ClientData_Header* New() const final {
    return CreateMaybeMessage<ClientData_Header>(nullptr);
  }

  ClientData_Header* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<ClientData_Header>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const ClientData_Header& from);
  void MergeFrom(const ClientData_Header& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ClientData_Header* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "ClientData_Header";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_RpcClient_2eproto);
    return ::descriptor_table_RpcClient_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kUserServiceFieldNumber = 1,
    kServiceMethodFieldNumber = 2,
  };
  // string UserService = 1;
  void clear_userservice();
  const std::string& userservice() const;
  void set_userservice(const std::string& value);
  void set_userservice(std::string&& value);
  void set_userservice(const char* value);
  void set_userservice(const char* value, size_t size);
  std::string* mutable_userservice();
  std::string* release_userservice();
  void set_allocated_userservice(std::string* userservice);
  private:
  const std::string& _internal_userservice() const;
  void _internal_set_userservice(const std::string& value);
  std::string* _internal_mutable_userservice();
  public:

  // string ServiceMethod = 2;
  void clear_servicemethod();
  const std::string& servicemethod() const;
  void set_servicemethod(const std::string& value);
  void set_servicemethod(std::string&& value);
  void set_servicemethod(const char* value);
  void set_servicemethod(const char* value, size_t size);
  std::string* mutable_servicemethod();
  std::string* release_servicemethod();
  void set_allocated_servicemethod(std::string* servicemethod);
  private:
  const std::string& _internal_servicemethod() const;
  void _internal_set_servicemethod(const std::string& value);
  std::string* _internal_mutable_servicemethod();
  public:

  // @@protoc_insertion_point(class_scope:ClientData_Header)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr userservice_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr servicemethod_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_RpcClient_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ClientData_Header

// string UserService = 1;
inline void ClientData_Header::clear_userservice() {
  userservice_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& ClientData_Header::userservice() const {
  // @@protoc_insertion_point(field_get:ClientData_Header.UserService)
  return _internal_userservice();
}
inline void ClientData_Header::set_userservice(const std::string& value) {
  _internal_set_userservice(value);
  // @@protoc_insertion_point(field_set:ClientData_Header.UserService)
}
inline std::string* ClientData_Header::mutable_userservice() {
  // @@protoc_insertion_point(field_mutable:ClientData_Header.UserService)
  return _internal_mutable_userservice();
}
inline const std::string& ClientData_Header::_internal_userservice() const {
  return userservice_.GetNoArena();
}
inline void ClientData_Header::_internal_set_userservice(const std::string& value) {
  
  userservice_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void ClientData_Header::set_userservice(std::string&& value) {
  
  userservice_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:ClientData_Header.UserService)
}
inline void ClientData_Header::set_userservice(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  userservice_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:ClientData_Header.UserService)
}
inline void ClientData_Header::set_userservice(const char* value, size_t size) {
  
  userservice_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:ClientData_Header.UserService)
}
inline std::string* ClientData_Header::_internal_mutable_userservice() {
  
  return userservice_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* ClientData_Header::release_userservice() {
  // @@protoc_insertion_point(field_release:ClientData_Header.UserService)
  
  return userservice_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void ClientData_Header::set_allocated_userservice(std::string* userservice) {
  if (userservice != nullptr) {
    
  } else {
    
  }
  userservice_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), userservice);
  // @@protoc_insertion_point(field_set_allocated:ClientData_Header.UserService)
}

// string ServiceMethod = 2;
inline void ClientData_Header::clear_servicemethod() {
  servicemethod_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& ClientData_Header::servicemethod() const {
  // @@protoc_insertion_point(field_get:ClientData_Header.ServiceMethod)
  return _internal_servicemethod();
}
inline void ClientData_Header::set_servicemethod(const std::string& value) {
  _internal_set_servicemethod(value);
  // @@protoc_insertion_point(field_set:ClientData_Header.ServiceMethod)
}
inline std::string* ClientData_Header::mutable_servicemethod() {
  // @@protoc_insertion_point(field_mutable:ClientData_Header.ServiceMethod)
  return _internal_mutable_servicemethod();
}
inline const std::string& ClientData_Header::_internal_servicemethod() const {
  return servicemethod_.GetNoArena();
}
inline void ClientData_Header::_internal_set_servicemethod(const std::string& value) {
  
  servicemethod_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void ClientData_Header::set_servicemethod(std::string&& value) {
  
  servicemethod_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:ClientData_Header.ServiceMethod)
}
inline void ClientData_Header::set_servicemethod(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  servicemethod_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:ClientData_Header.ServiceMethod)
}
inline void ClientData_Header::set_servicemethod(const char* value, size_t size) {
  
  servicemethod_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:ClientData_Header.ServiceMethod)
}
inline std::string* ClientData_Header::_internal_mutable_servicemethod() {
  
  return servicemethod_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* ClientData_Header::release_servicemethod() {
  // @@protoc_insertion_point(field_release:ClientData_Header.ServiceMethod)
  
  return servicemethod_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void ClientData_Header::set_allocated_servicemethod(std::string* servicemethod) {
  if (servicemethod != nullptr) {
    
  } else {
    
  }
  servicemethod_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), servicemethod);
  // @@protoc_insertion_point(field_set_allocated:ClientData_Header.ServiceMethod)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_RpcClient_2eproto