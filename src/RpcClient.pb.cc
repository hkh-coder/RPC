// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: RpcClient.proto

#include "RpcClient.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
class ClientData_HeaderDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<ClientData_Header> _instance;
} _ClientData_Header_default_instance_;
static void InitDefaultsscc_info_ClientData_Header_RpcClient_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_ClientData_Header_default_instance_;
    new (ptr) ::ClientData_Header();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::ClientData_Header::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_ClientData_Header_RpcClient_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_ClientData_Header_RpcClient_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_RpcClient_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_RpcClient_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_RpcClient_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_RpcClient_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::ClientData_Header, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::ClientData_Header, userservice_),
  PROTOBUF_FIELD_OFFSET(::ClientData_Header, servicemethod_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::ClientData_Header)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_ClientData_Header_default_instance_),
};

const char descriptor_table_protodef_RpcClient_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\017RpcClient.proto\"\?\n\021ClientData_Header\022\023"
  "\n\013UserService\030\001 \001(\t\022\025\n\rServiceMethod\030\002 \001"
  "(\tB\003\200\001\001b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_RpcClient_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_RpcClient_2eproto_sccs[1] = {
  &scc_info_ClientData_Header_RpcClient_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_RpcClient_2eproto_once;
static bool descriptor_table_RpcClient_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_RpcClient_2eproto = {
  &descriptor_table_RpcClient_2eproto_initialized, descriptor_table_protodef_RpcClient_2eproto, "RpcClient.proto", 95,
  &descriptor_table_RpcClient_2eproto_once, descriptor_table_RpcClient_2eproto_sccs, descriptor_table_RpcClient_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_RpcClient_2eproto::offsets,
  file_level_metadata_RpcClient_2eproto, 1, file_level_enum_descriptors_RpcClient_2eproto, file_level_service_descriptors_RpcClient_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_RpcClient_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_RpcClient_2eproto), true);

// ===================================================================

void ClientData_Header::InitAsDefaultInstance() {
}
class ClientData_Header::_Internal {
 public:
};

ClientData_Header::ClientData_Header()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:ClientData_Header)
}
ClientData_Header::ClientData_Header(const ClientData_Header& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  userservice_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_userservice().empty()) {
    userservice_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.userservice_);
  }
  servicemethod_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_servicemethod().empty()) {
    servicemethod_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.servicemethod_);
  }
  // @@protoc_insertion_point(copy_constructor:ClientData_Header)
}

void ClientData_Header::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_ClientData_Header_RpcClient_2eproto.base);
  userservice_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  servicemethod_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

ClientData_Header::~ClientData_Header() {
  // @@protoc_insertion_point(destructor:ClientData_Header)
  SharedDtor();
}

void ClientData_Header::SharedDtor() {
  userservice_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  servicemethod_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void ClientData_Header::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ClientData_Header& ClientData_Header::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_ClientData_Header_RpcClient_2eproto.base);
  return *internal_default_instance();
}


void ClientData_Header::Clear() {
// @@protoc_insertion_point(message_clear_start:ClientData_Header)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  userservice_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  servicemethod_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _internal_metadata_.Clear();
}

const char* ClientData_Header::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string UserService = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_userservice();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "ClientData_Header.UserService"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string ServiceMethod = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_servicemethod();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "ClientData_Header.ServiceMethod"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* ClientData_Header::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:ClientData_Header)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string UserService = 1;
  if (this->userservice().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_userservice().data(), static_cast<int>(this->_internal_userservice().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "ClientData_Header.UserService");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_userservice(), target);
  }

  // string ServiceMethod = 2;
  if (this->servicemethod().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_servicemethod().data(), static_cast<int>(this->_internal_servicemethod().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "ClientData_Header.ServiceMethod");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_servicemethod(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ClientData_Header)
  return target;
}

size_t ClientData_Header::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:ClientData_Header)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string UserService = 1;
  if (this->userservice().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_userservice());
  }

  // string ServiceMethod = 2;
  if (this->servicemethod().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_servicemethod());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void ClientData_Header::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:ClientData_Header)
  GOOGLE_DCHECK_NE(&from, this);
  const ClientData_Header* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<ClientData_Header>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:ClientData_Header)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:ClientData_Header)
    MergeFrom(*source);
  }
}

void ClientData_Header::MergeFrom(const ClientData_Header& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:ClientData_Header)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.userservice().size() > 0) {

    userservice_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.userservice_);
  }
  if (from.servicemethod().size() > 0) {

    servicemethod_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.servicemethod_);
  }
}

void ClientData_Header::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:ClientData_Header)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ClientData_Header::CopyFrom(const ClientData_Header& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ClientData_Header)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ClientData_Header::IsInitialized() const {
  return true;
}

void ClientData_Header::InternalSwap(ClientData_Header* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  userservice_.Swap(&other->userservice_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  servicemethod_.Swap(&other->servicemethod_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
}

::PROTOBUF_NAMESPACE_ID::Metadata ClientData_Header::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::ClientData_Header* Arena::CreateMaybeMessage< ::ClientData_Header >(Arena* arena) {
  return Arena::CreateInternal< ::ClientData_Header >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
