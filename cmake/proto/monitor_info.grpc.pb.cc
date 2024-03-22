// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: monitor_info.proto

#include "monitor_info.pb.h"
#include "monitor_info.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace monitor {
namespace proto {

static const char* GrpcManager_method_names[] = {
  "/monitor.proto.GrpcManager/SetMonitorInfo",
  "/monitor.proto.GrpcManager/GetHostID",
  "/monitor.proto.GrpcManager/GetMonitorInfo",
};

std::unique_ptr< GrpcManager::Stub> GrpcManager::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< GrpcManager::Stub> stub(new GrpcManager::Stub(channel));
  return stub;
}

GrpcManager::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_SetMonitorInfo_(GrpcManager_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetHostID_(GrpcManager_method_names[1], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetMonitorInfo_(GrpcManager_method_names[2], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status GrpcManager::Stub::SetMonitorInfo(::grpc::ClientContext* context, const ::monitor::proto::MonitorInfo& request, ::google::protobuf::Empty* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_SetMonitorInfo_, context, request, response);
}

void GrpcManager::Stub::experimental_async::SetMonitorInfo(::grpc::ClientContext* context, const ::monitor::proto::MonitorInfo* request, ::google::protobuf::Empty* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_SetMonitorInfo_, context, request, response, std::move(f));
}

void GrpcManager::Stub::experimental_async::SetMonitorInfo(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::google::protobuf::Empty* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_SetMonitorInfo_, context, request, response, std::move(f));
}

void GrpcManager::Stub::experimental_async::SetMonitorInfo(::grpc::ClientContext* context, const ::monitor::proto::MonitorInfo* request, ::google::protobuf::Empty* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_SetMonitorInfo_, context, request, response, reactor);
}

void GrpcManager::Stub::experimental_async::SetMonitorInfo(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::google::protobuf::Empty* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_SetMonitorInfo_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>* GrpcManager::Stub::AsyncSetMonitorInfoRaw(::grpc::ClientContext* context, const ::monitor::proto::MonitorInfo& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::google::protobuf::Empty>::Create(channel_.get(), cq, rpcmethod_SetMonitorInfo_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::google::protobuf::Empty>* GrpcManager::Stub::PrepareAsyncSetMonitorInfoRaw(::grpc::ClientContext* context, const ::monitor::proto::MonitorInfo& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::google::protobuf::Empty>::Create(channel_.get(), cq, rpcmethod_SetMonitorInfo_, context, request, false);
}

::grpc::Status GrpcManager::Stub::GetHostID(::grpc::ClientContext* context, const ::monitor::proto::HostInfo& request, ::monitor::proto::HostID* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_GetHostID_, context, request, response);
}

void GrpcManager::Stub::experimental_async::GetHostID(::grpc::ClientContext* context, const ::monitor::proto::HostInfo* request, ::monitor::proto::HostID* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_GetHostID_, context, request, response, std::move(f));
}

void GrpcManager::Stub::experimental_async::GetHostID(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::monitor::proto::HostID* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_GetHostID_, context, request, response, std::move(f));
}

void GrpcManager::Stub::experimental_async::GetHostID(::grpc::ClientContext* context, const ::monitor::proto::HostInfo* request, ::monitor::proto::HostID* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_GetHostID_, context, request, response, reactor);
}

void GrpcManager::Stub::experimental_async::GetHostID(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::monitor::proto::HostID* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_GetHostID_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::monitor::proto::HostID>* GrpcManager::Stub::AsyncGetHostIDRaw(::grpc::ClientContext* context, const ::monitor::proto::HostInfo& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::monitor::proto::HostID>::Create(channel_.get(), cq, rpcmethod_GetHostID_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::monitor::proto::HostID>* GrpcManager::Stub::PrepareAsyncGetHostIDRaw(::grpc::ClientContext* context, const ::monitor::proto::HostInfo& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::monitor::proto::HostID>::Create(channel_.get(), cq, rpcmethod_GetHostID_, context, request, false);
}

::grpc::Status GrpcManager::Stub::GetMonitorInfo(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::monitor::proto::MonitorInfo* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_GetMonitorInfo_, context, request, response);
}

void GrpcManager::Stub::experimental_async::GetMonitorInfo(::grpc::ClientContext* context, const ::google::protobuf::Empty* request, ::monitor::proto::MonitorInfo* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_GetMonitorInfo_, context, request, response, std::move(f));
}

void GrpcManager::Stub::experimental_async::GetMonitorInfo(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::monitor::proto::MonitorInfo* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_GetMonitorInfo_, context, request, response, std::move(f));
}

void GrpcManager::Stub::experimental_async::GetMonitorInfo(::grpc::ClientContext* context, const ::google::protobuf::Empty* request, ::monitor::proto::MonitorInfo* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_GetMonitorInfo_, context, request, response, reactor);
}

void GrpcManager::Stub::experimental_async::GetMonitorInfo(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::monitor::proto::MonitorInfo* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_GetMonitorInfo_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::monitor::proto::MonitorInfo>* GrpcManager::Stub::AsyncGetMonitorInfoRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::monitor::proto::MonitorInfo>::Create(channel_.get(), cq, rpcmethod_GetMonitorInfo_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::monitor::proto::MonitorInfo>* GrpcManager::Stub::PrepareAsyncGetMonitorInfoRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::monitor::proto::MonitorInfo>::Create(channel_.get(), cq, rpcmethod_GetMonitorInfo_, context, request, false);
}

GrpcManager::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      GrpcManager_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< GrpcManager::Service, ::monitor::proto::MonitorInfo, ::google::protobuf::Empty>(
          [](GrpcManager::Service* service,
             ::grpc_impl::ServerContext* ctx,
             const ::monitor::proto::MonitorInfo* req,
             ::google::protobuf::Empty* resp) {
               return service->SetMonitorInfo(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      GrpcManager_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< GrpcManager::Service, ::monitor::proto::HostInfo, ::monitor::proto::HostID>(
          [](GrpcManager::Service* service,
             ::grpc_impl::ServerContext* ctx,
             const ::monitor::proto::HostInfo* req,
             ::monitor::proto::HostID* resp) {
               return service->GetHostID(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      GrpcManager_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< GrpcManager::Service, ::google::protobuf::Empty, ::monitor::proto::MonitorInfo>(
          [](GrpcManager::Service* service,
             ::grpc_impl::ServerContext* ctx,
             const ::google::protobuf::Empty* req,
             ::monitor::proto::MonitorInfo* resp) {
               return service->GetMonitorInfo(ctx, req, resp);
             }, this)));
}

GrpcManager::Service::~Service() {
}

::grpc::Status GrpcManager::Service::SetMonitorInfo(::grpc::ServerContext* context, const ::monitor::proto::MonitorInfo* request, ::google::protobuf::Empty* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status GrpcManager::Service::GetHostID(::grpc::ServerContext* context, const ::monitor::proto::HostInfo* request, ::monitor::proto::HostID* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status GrpcManager::Service::GetMonitorInfo(::grpc::ServerContext* context, const ::google::protobuf::Empty* request, ::monitor::proto::MonitorInfo* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace monitor
}  // namespace proto

