#include <SenseKitAPI.h>
#include <Plugins/StreamServiceProxy.h>
#include <cassert>
#include <iostream>
using std::cout;
using std::endl;

SENSEKIT_BEGIN_DECLS

SENSEKIT_LOCAL StreamServiceProxyBase* __sensekit_api_proxy_ptr = nullptr;

inline sensekit::StreamServiceProxy* get_api_proxy()
{
    return reinterpret_cast<sensekit::StreamServiceProxy*>(__sensekit_api_proxy_ptr);
}

SENSEKIT_API_PROXY StreamServiceProxyBase* sensekit_api_get_proxy()
{
    return __sensekit_api_proxy_ptr;
}

SENSEKIT_API_PROXY void sensekit_api_set_proxy(StreamServiceProxyBase* proxy)
{
    __sensekit_api_proxy_ptr = proxy;
}

SENSEKIT_API sensekit_status_t sensekit_streamset_open(const char* connection_string,
                                                             sensekit_streamset_t** streamset)
{
    return get_api_proxy()->open_streamset(connection_string,
                                           streamset);
}

SENSEKIT_API sensekit_status_t sensekit_streamset_close(sensekit_streamset_t** streamset)
{
    return get_api_proxy()->close_streamset(streamset);
}

SENSEKIT_API sensekit_status_t sensekit_reader_create(sensekit_streamset_t* streamSet, sensekit_reader_t** reader)
{
    return get_api_proxy()->create_reader(streamSet, reader);
}

SENSEKIT_API sensekit_status_t sensekit_reader_destroy(sensekit_reader_t** reader)
{
    return get_api_proxy()->destroy_reader(reader);
}

SENSEKIT_API sensekit_status_t sensekit_reader_get_stream(sensekit_reader_t* reader,
                                                                sensekit_stream_type_t type,
                                                                sensekit_stream_subtype_t subType,
                                                                sensekit_streamconnection_t** connection)
{
    return get_api_proxy()->get_stream(reader,
                                       type,
                                       subType,
                                       connection);
}

SENSEKIT_API sensekit_status_t sensekit_stream_start(sensekit_streamconnection_t* connection)
{
    return get_api_proxy()->start_stream(connection);
}

SENSEKIT_API sensekit_status_t sensekit_stream_stop(sensekit_streamconnection_t* connection)
{
    return get_api_proxy()->stop_stream(connection);
}

SENSEKIT_API sensekit_status_t sensekit_reader_open_frame(sensekit_reader_t* reader,
                                                                int timeout,
                                                                sensekit_reader_frame_t** frame)
{
    return get_api_proxy()->open_frame(reader, timeout, frame);
}

SENSEKIT_API sensekit_status_t sensekit_reader_close_frame(sensekit_reader_frame_t** frame)
{
    return get_api_proxy()->close_frame(frame);
}

SENSEKIT_API sensekit_status_t sensekit_reader_get_frame(sensekit_reader_frame_t* frame,
                                                         sensekit_stream_type_t type,
                                                         sensekit_stream_subtype_t subType,
                                                         sensekit_frame_ref_t** frameRef)
{
    return get_api_proxy()->get_frame(frame, type, subType, frameRef);
}


SENSEKIT_API sensekit_status_t sensekit_temp_update()
{
    return get_api_proxy()->temp_update();
}

SENSEKIT_API sensekit_status_t sensekit_stream_set_parameter(sensekit_streamconnection_t* connection,
                                                                   sensekit_parameter_id parameter_id,
                                                                   size_t byte_length,
                                                                   sensekit_parameter_data_t* data)
{
    return get_api_proxy()->set_parameter(connection, parameter_id, byte_length, data);
}

SENSEKIT_API sensekit_status_t sensekit_stream_get_parameter_size(sensekit_streamconnection_t* connection,
                                                                        sensekit_parameter_id parameter_id,
                                                                        size_t* byte_length)
{
    return get_api_proxy()->get_parameter_size(connection, parameter_id, byte_length);
}

SENSEKIT_API sensekit_status_t sensekit_stream_get_parameter_data(sensekit_streamconnection_t* connection,
                                                                        sensekit_parameter_id parameter_id,
                                                                        size_t byte_length,
                                                                        sensekit_parameter_data_t* data)
{
    return get_api_proxy()->get_parameter_data(connection, parameter_id, byte_length, data);
}

SENSEKIT_END_DECLS