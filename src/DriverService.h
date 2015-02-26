#ifndef DRIVERSERVICE_H
#define DRIVERSERVICE_H

#include <SenseKit.h>
#include "Signal.h"
#include "DriverAdapter.h"
#include "Device.h"

namespace sensekit {

    class DriverService
    {
    public:

        typedef Signal<Device*> DeviceConnectedSignal;
        typedef DeviceConnectedSignal::callback_type DeviceConnectedCallback;
        typedef Signal<void> DeviceDisconnectedSignal;
        typedef DeviceDisconnectedSignal::callback_type DeviceDisconnectedCallback;
        typedef Signal<void> DeviceChangedSignal;
        typedef DeviceChangedSignal::callback_type DeviceChangedCallback;

        typedef size_t CallbackId;

        DriverService(DriverAdapter& driverAdapter)
            : m_driverAdapter(driverAdapter)
            {}

        ~DriverService() {}

        sensekit_status_t initialize();
        sensekit_status_t destroy();

        CallbackId registerDeviceConnectedCallback(DeviceConnectedCallback callback)
            { return m_connectedSignal += callback; };
        CallbackId registerDeviceDisconnectedCallback(DeviceDisconnectedCallback callback)
            { return m_disconnectedSignal += callback; };
        CallbackId registerDeviceChangedCallback(DeviceChangedCallback callback)
            { return m_changedSignal += callback; };

        bool unregisterDeviceConnectedCallback(CallbackId callbackId)
            { return m_connectedSignal -= callbackId; };
        bool unregisterDeviceDisconnectedCallback(CallbackId callbackId)
            { return m_disconnectedSignal -= callbackId; };
        bool unregisterDeviceChangedCallback(CallbackId callbackId)
            { return m_changedSignal -= callbackId; };
    private:

        DriverAdapter& m_driverAdapter;

        DeviceConnectedSignal m_connectedSignal;
        DeviceDisconnectedSignal m_disconnectedSignal;
        DeviceChangedSignal m_changedSignal;

        static void adapter_deviceConnected(DriverAdapter* adapter, device_handle_t deviceHandle, void* context);
        static void adapter_deviceDisconnected(void* context);
        static void adapter_deviceChanged(void* context);
    };
}

#endif /* DRIVERSERVICE_H */
