/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.7 */

#ifndef PB_MESHTASTIC_MESHTASTIC_ADMIN_PB_H_INCLUDED
#define PB_MESHTASTIC_MESHTASTIC_ADMIN_PB_H_INCLUDED
#include <pb.h>
#include "meshtastic/channel.pb.h"
#include "meshtastic/config.pb.h"
#include "meshtastic/device_metadata.pb.h"
#include "meshtastic/mesh.pb.h"
#include "meshtastic/module_config.pb.h"
#include "meshtastic/connection_status.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Enum definitions */
/* TODO: REPLACE */
typedef enum _meshtastic_AdminMessage_ConfigType {
    /* TODO: REPLACE */
    meshtastic_AdminMessage_ConfigType_DEVICE_CONFIG = 0,
    /* TODO: REPLACE */
    meshtastic_AdminMessage_ConfigType_POSITION_CONFIG = 1,
    /* TODO: REPLACE */
    meshtastic_AdminMessage_ConfigType_POWER_CONFIG = 2,
    /* TODO: REPLACE */
    meshtastic_AdminMessage_ConfigType_NETWORK_CONFIG = 3,
    /* TODO: REPLACE */
    meshtastic_AdminMessage_ConfigType_DISPLAY_CONFIG = 4,
    /* TODO: REPLACE */
    meshtastic_AdminMessage_ConfigType_LORA_CONFIG = 5,
    /* TODO: REPLACE */
    meshtastic_AdminMessage_ConfigType_BLUETOOTH_CONFIG = 6
} meshtastic_AdminMessage_ConfigType;

/* TODO: REPLACE */
typedef enum _meshtastic_AdminMessage_ModuleConfigType {
    /* TODO: REPLACE */
    meshtastic_AdminMessage_ModuleConfigType_MQTT_CONFIG = 0,
    /* TODO: REPLACE */
    meshtastic_AdminMessage_ModuleConfigType_SERIAL_CONFIG = 1,
    /* TODO: REPLACE */
    meshtastic_AdminMessage_ModuleConfigType_EXTNOTIF_CONFIG = 2,
    /* TODO: REPLACE */
    meshtastic_AdminMessage_ModuleConfigType_STOREFORWARD_CONFIG = 3,
    /* TODO: REPLACE */
    meshtastic_AdminMessage_ModuleConfigType_RANGETEST_CONFIG = 4,
    /* TODO: REPLACE */
    meshtastic_AdminMessage_ModuleConfigType_TELEMETRY_CONFIG = 5,
    /* TODO: REPLACE */
    meshtastic_AdminMessage_ModuleConfigType_CANNEDMSG_CONFIG = 6,
    /* TODO: REPLACE */
    meshtastic_AdminMessage_ModuleConfigType_AUDIO_CONFIG = 7,
    /* TODO: REPLACE */
    meshtastic_AdminMessage_ModuleConfigType_REMOTEHARDWARE_CONFIG = 8
} meshtastic_AdminMessage_ModuleConfigType;

/* Struct definitions */
/* This message is handled by the Admin module and is responsible for all settings/channel read/write operations.
 This message is used to do settings operations to both remote AND local nodes.
 (Prior to 1.2 these operations were done via special ToRadio operations) */
typedef struct _meshtastic_AdminMessage {
    pb_size_t which_payload_variant;
    union {
        /* Send the specified channel in the response to this message
     NOTE: This field is sent with the channel index + 1 (to ensure we never try to send 'zero' - which protobufs treats as not present) */
        uint32_t get_channel_request;
        /* TODO: REPLACE */
        meshtastic_Channel get_channel_response;
        /* Send the current owner data in the response to this message. */
        bool get_owner_request;
        /* TODO: REPLACE */
        meshtastic_User get_owner_response;
        /* Ask for the following config data to be sent */
        meshtastic_AdminMessage_ConfigType get_config_request;
        /* Send the current Config in the response to this message. */
        meshtastic_Config get_config_response;
        /* Ask for the following config data to be sent */
        meshtastic_AdminMessage_ModuleConfigType get_module_config_request;
        /* Send the current Config in the response to this message. */
        meshtastic_ModuleConfig get_module_config_response;
        /* Get the Canned Message Module messages in the response to this message. */
        bool get_canned_message_module_messages_request;
        /* Get the Canned Message Module messages in the response to this message. */
        char get_canned_message_module_messages_response[201];
        /* Request the node to send device metadata (firmware, protobuf version, etc) */
        bool get_device_metadata_request;
        /* Device metadata response */
        meshtastic_DeviceMetadata get_device_metadata_response;
        /* Get the Ringtone in the response to this message. */
        bool get_ringtone_request;
        /* Get the Ringtone in the response to this message. */
        char get_ringtone_response[231];
        /* Request the node to send it's connection status */
        bool get_device_connection_status_request;
        /* Device connection status response */
        meshtastic_DeviceConnectionStatus get_device_connection_status_response;
        /* Set the owner for this node */
        meshtastic_User set_owner;
        /* Set channels (using the new API).
     A special channel is the "primary channel".
     The other records are secondary channels.
     Note: only one channel can be marked as primary.
     If the client sets a particular channel to be primary, the previous channel will be set to SECONDARY automatically. */
        meshtastic_Channel set_channel;
        /* Set the current Config */
        meshtastic_Config set_config;
        /* Set the current Config */
        meshtastic_ModuleConfig set_module_config;
        /* Set the Canned Message Module messages text. */
        char set_canned_message_module_messages[201];
        /* Set the ringtone for ExternalNotification. */
        char set_ringtone_message[231];
        /* Begins an edit transaction for config, module config, owner, and channel settings changes
     This will delay the standard *implicit* save to the file system and subsequent reboot behavior until committed (commit_edit_settings) */
        bool begin_edit_settings;
        /* Commits an open transaction for any edits made to config, module config, owner, and channel settings */
        bool commit_edit_settings;
        /* Tell the node to reboot into the OTA Firmware in this many seconds (or <0 to cancel reboot)
     Only Implemented for ESP32 Devices. This needs to be issued to send a new main firmware via bluetooth. */
        int32_t reboot_ota_seconds;
        /* This message is only supported for the simulator porduino build.
     If received the simulator will exit successfully. */
        bool exit_simulator;
        /* Tell the node to reboot in this many seconds (or <0 to cancel reboot) */
        int32_t reboot_seconds;
        /* Tell the node to shutdown in this many seconds (or <0 to cancel shutdown) */
        int32_t shutdown_seconds;
        /* Tell the node to factory reset, all device settings will be returned to factory defaults. */
        int32_t factory_reset;
        /* Tell the node to reset the nodedb. */
        int32_t nodedb_reset;
    };
} meshtastic_AdminMessage;


#ifdef __cplusplus
extern "C" {
#endif

/* Helper constants for enums */
#define _meshtastic_AdminMessage_ConfigType_MIN meshtastic_AdminMessage_ConfigType_DEVICE_CONFIG
#define _meshtastic_AdminMessage_ConfigType_MAX meshtastic_AdminMessage_ConfigType_BLUETOOTH_CONFIG
#define _meshtastic_AdminMessage_ConfigType_ARRAYSIZE ((meshtastic_AdminMessage_ConfigType)(meshtastic_AdminMessage_ConfigType_BLUETOOTH_CONFIG+1))

#define _meshtastic_AdminMessage_ModuleConfigType_MIN meshtastic_AdminMessage_ModuleConfigType_MQTT_CONFIG
#define _meshtastic_AdminMessage_ModuleConfigType_MAX meshtastic_AdminMessage_ModuleConfigType_REMOTEHARDWARE_CONFIG
#define _meshtastic_AdminMessage_ModuleConfigType_ARRAYSIZE ((meshtastic_AdminMessage_ModuleConfigType)(meshtastic_AdminMessage_ModuleConfigType_REMOTEHARDWARE_CONFIG+1))

#define meshtastic_AdminMessage_payload_variant_get_config_request_ENUMTYPE meshtastic_AdminMessage_ConfigType
#define meshtastic_AdminMessage_payload_variant_get_module_config_request_ENUMTYPE meshtastic_AdminMessage_ModuleConfigType


/* Initializer values for message structs */
#define meshtastic_AdminMessage_init_default     {0, {0}}
#define meshtastic_AdminMessage_init_zero        {0, {0}}

/* Field tags (for use in manual encoding/decoding) */
#define meshtastic_AdminMessage_get_channel_request_tag 1
#define meshtastic_AdminMessage_get_channel_response_tag 2
#define meshtastic_AdminMessage_get_owner_request_tag 3
#define meshtastic_AdminMessage_get_owner_response_tag 4
#define meshtastic_AdminMessage_get_config_request_tag 5
#define meshtastic_AdminMessage_get_config_response_tag 6
#define meshtastic_AdminMessage_get_module_config_request_tag 7
#define meshtastic_AdminMessage_get_module_config_response_tag 8
#define meshtastic_AdminMessage_get_canned_message_module_messages_request_tag 10
#define meshtastic_AdminMessage_get_canned_message_module_messages_response_tag 11
#define meshtastic_AdminMessage_get_device_metadata_request_tag 12
#define meshtastic_AdminMessage_get_device_metadata_response_tag 13
#define meshtastic_AdminMessage_get_ringtone_request_tag 14
#define meshtastic_AdminMessage_get_ringtone_response_tag 15
#define meshtastic_AdminMessage_get_device_connection_status_request_tag 16
#define meshtastic_AdminMessage_get_device_connection_status_response_tag 17
#define meshtastic_AdminMessage_set_owner_tag    32
#define meshtastic_AdminMessage_set_channel_tag  33
#define meshtastic_AdminMessage_set_config_tag   34
#define meshtastic_AdminMessage_set_module_config_tag 35
#define meshtastic_AdminMessage_set_canned_message_module_messages_tag 36
#define meshtastic_AdminMessage_set_ringtone_message_tag 37
#define meshtastic_AdminMessage_begin_edit_settings_tag 64
#define meshtastic_AdminMessage_commit_edit_settings_tag 65
#define meshtastic_AdminMessage_reboot_ota_seconds_tag 95
#define meshtastic_AdminMessage_exit_simulator_tag 96
#define meshtastic_AdminMessage_reboot_seconds_tag 97
#define meshtastic_AdminMessage_shutdown_seconds_tag 98
#define meshtastic_AdminMessage_factory_reset_tag 99
#define meshtastic_AdminMessage_nodedb_reset_tag 100

/* Struct field encoding specification for nanopb */
#define meshtastic_AdminMessage_FIELDLIST(X, a) \
X(a, STATIC,   ONEOF,    UINT32,   (payload_variant,get_channel_request,get_channel_request),   1) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload_variant,get_channel_response,get_channel_response),   2) \
X(a, STATIC,   ONEOF,    BOOL,     (payload_variant,get_owner_request,get_owner_request),   3) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload_variant,get_owner_response,get_owner_response),   4) \
X(a, STATIC,   ONEOF,    UENUM,    (payload_variant,get_config_request,get_config_request),   5) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload_variant,get_config_response,get_config_response),   6) \
X(a, STATIC,   ONEOF,    UENUM,    (payload_variant,get_module_config_request,get_module_config_request),   7) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload_variant,get_module_config_response,get_module_config_response),   8) \
X(a, STATIC,   ONEOF,    BOOL,     (payload_variant,get_canned_message_module_messages_request,get_canned_message_module_messages_request),  10) \
X(a, STATIC,   ONEOF,    STRING,   (payload_variant,get_canned_message_module_messages_response,get_canned_message_module_messages_response),  11) \
X(a, STATIC,   ONEOF,    BOOL,     (payload_variant,get_device_metadata_request,get_device_metadata_request),  12) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload_variant,get_device_metadata_response,get_device_metadata_response),  13) \
X(a, STATIC,   ONEOF,    BOOL,     (payload_variant,get_ringtone_request,get_ringtone_request),  14) \
X(a, STATIC,   ONEOF,    STRING,   (payload_variant,get_ringtone_response,get_ringtone_response),  15) \
X(a, STATIC,   ONEOF,    BOOL,     (payload_variant,get_device_connection_status_request,get_device_connection_status_request),  16) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload_variant,get_device_connection_status_response,get_device_connection_status_response),  17) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload_variant,set_owner,set_owner),  32) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload_variant,set_channel,set_channel),  33) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload_variant,set_config,set_config),  34) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload_variant,set_module_config,set_module_config),  35) \
X(a, STATIC,   ONEOF,    STRING,   (payload_variant,set_canned_message_module_messages,set_canned_message_module_messages),  36) \
X(a, STATIC,   ONEOF,    STRING,   (payload_variant,set_ringtone_message,set_ringtone_message),  37) \
X(a, STATIC,   ONEOF,    BOOL,     (payload_variant,begin_edit_settings,begin_edit_settings),  64) \
X(a, STATIC,   ONEOF,    BOOL,     (payload_variant,commit_edit_settings,commit_edit_settings),  65) \
X(a, STATIC,   ONEOF,    INT32,    (payload_variant,reboot_ota_seconds,reboot_ota_seconds),  95) \
X(a, STATIC,   ONEOF,    BOOL,     (payload_variant,exit_simulator,exit_simulator),  96) \
X(a, STATIC,   ONEOF,    INT32,    (payload_variant,reboot_seconds,reboot_seconds),  97) \
X(a, STATIC,   ONEOF,    INT32,    (payload_variant,shutdown_seconds,shutdown_seconds),  98) \
X(a, STATIC,   ONEOF,    INT32,    (payload_variant,factory_reset,factory_reset),  99) \
X(a, STATIC,   ONEOF,    INT32,    (payload_variant,nodedb_reset,nodedb_reset), 100)
#define meshtastic_AdminMessage_CALLBACK NULL
#define meshtastic_AdminMessage_DEFAULT NULL
#define meshtastic_AdminMessage_payload_variant_get_channel_response_MSGTYPE meshtastic_Channel
#define meshtastic_AdminMessage_payload_variant_get_owner_response_MSGTYPE meshtastic_User
#define meshtastic_AdminMessage_payload_variant_get_config_response_MSGTYPE meshtastic_Config
#define meshtastic_AdminMessage_payload_variant_get_module_config_response_MSGTYPE meshtastic_ModuleConfig
#define meshtastic_AdminMessage_payload_variant_get_device_metadata_response_MSGTYPE meshtastic_DeviceMetadata
#define meshtastic_AdminMessage_payload_variant_get_device_connection_status_response_MSGTYPE meshtastic_DeviceConnectionStatus
#define meshtastic_AdminMessage_payload_variant_set_owner_MSGTYPE meshtastic_User
#define meshtastic_AdminMessage_payload_variant_set_channel_MSGTYPE meshtastic_Channel
#define meshtastic_AdminMessage_payload_variant_set_config_MSGTYPE meshtastic_Config
#define meshtastic_AdminMessage_payload_variant_set_module_config_MSGTYPE meshtastic_ModuleConfig

extern const pb_msgdesc_t meshtastic_AdminMessage_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define meshtastic_AdminMessage_fields &meshtastic_AdminMessage_msg

/* Maximum encoded size of messages (where known) */
#define meshtastic_AdminMessage_size             234

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
