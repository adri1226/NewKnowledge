

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from chocolate_factory.idl
using RTI Code Generator (rtiddsgen) version 3.1.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef chocolate_factoryPlugin_1422893627_h
#define chocolate_factoryPlugin_1422893627_h

#include "chocolate_factory.hpp"

struct RTICdrStream;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#define TemperaturePlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define TemperaturePlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer
#define TemperaturePlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define TemperaturePlugin_create_sample PRESTypePluginDefaultEndpointData_createSample
#define TemperaturePlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern Temperature*
TemperaturePluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern Temperature*
TemperaturePluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern Temperature*
TemperaturePluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool
TemperaturePluginSupport_copy_data(
    Temperature *out,
    const Temperature *in);

NDDSUSERDllExport extern void
TemperaturePluginSupport_destroy_data_w_params(
    Temperature *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void
TemperaturePluginSupport_destroy_data_ex(
    Temperature *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void
TemperaturePluginSupport_destroy_data(
    Temperature *sample);

NDDSUSERDllExport extern void
TemperaturePluginSupport_print_data(
    const Temperature *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData
TemperaturePlugin_on_participant_attached(
    void *registration_data,
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration,
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void
TemperaturePlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData
TemperaturePlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration,
    void *container_plugin_context);

NDDSUSERDllExport extern void
TemperaturePlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void
TemperaturePlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    Temperature *sample,
    void *handle);

NDDSUSERDllExport extern RTIBool
TemperaturePlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    Temperature *out,
    const Temperature *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
TemperaturePlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const Temperature *sample,
    ::dds::core::policy::DataRepresentationId representation
    = ::dds::core::policy::DataRepresentation::xcdr());

NDDSUSERDllExport extern RTIBool
TemperaturePlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    Temperature **sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
TemperaturePlugin_deserialize_from_cdr_buffer(
    Temperature *sample,
    const char * buffer,
    unsigned int length);

NDDSUSERDllExport extern unsigned int
TemperaturePlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind
TemperaturePlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int
TemperaturePlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
TemperaturePlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool
TemperaturePlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    Temperature ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
TemperaturePlugin_new(void);

NDDSUSERDllExport extern void
TemperaturePlugin_delete(struct PRESTypePlugin *);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern unsigned int
LotStatusKindPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern unsigned int
LotStatusKindPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
LotStatusKindPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* ----------------------------------------------------------------------------
Support functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern void
LotStatusKindPluginSupport_print_data(
    const LotStatusKind *sample, const char *desc, int indent_level);

#define ChocolateLotStatePlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define ChocolateLotStatePlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer
#define ChocolateLotStatePlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define ChocolateLotStatePlugin_create_sample PRESTypePluginDefaultEndpointData_createSample
#define ChocolateLotStatePlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern ChocolateLotState*
ChocolateLotStatePluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern ChocolateLotState*
ChocolateLotStatePluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern ChocolateLotState*
ChocolateLotStatePluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool
ChocolateLotStatePluginSupport_copy_data(
    ChocolateLotState *out,
    const ChocolateLotState *in);

NDDSUSERDllExport extern void
ChocolateLotStatePluginSupport_destroy_data_w_params(
    ChocolateLotState *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void
ChocolateLotStatePluginSupport_destroy_data_ex(
    ChocolateLotState *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void
ChocolateLotStatePluginSupport_destroy_data(
    ChocolateLotState *sample);

NDDSUSERDllExport extern void
ChocolateLotStatePluginSupport_print_data(
    const ChocolateLotState *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData
ChocolateLotStatePlugin_on_participant_attached(
    void *registration_data,
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration,
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void
ChocolateLotStatePlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData
ChocolateLotStatePlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration,
    void *container_plugin_context);

NDDSUSERDllExport extern void
ChocolateLotStatePlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void
ChocolateLotStatePlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    ChocolateLotState *sample,
    void *handle);

NDDSUSERDllExport extern RTIBool
ChocolateLotStatePlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    ChocolateLotState *out,
    const ChocolateLotState *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
ChocolateLotStatePlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const ChocolateLotState *sample,
    ::dds::core::policy::DataRepresentationId representation
    = ::dds::core::policy::DataRepresentation::xcdr());

NDDSUSERDllExport extern RTIBool
ChocolateLotStatePlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    ChocolateLotState **sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
ChocolateLotStatePlugin_deserialize_from_cdr_buffer(
    ChocolateLotState *sample,
    const char * buffer,
    unsigned int length);

NDDSUSERDllExport extern unsigned int
ChocolateLotStatePlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind
ChocolateLotStatePlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int
ChocolateLotStatePlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
ChocolateLotStatePlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool
ChocolateLotStatePlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    ChocolateLotState ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
ChocolateLotStatePlugin_new(void);

NDDSUSERDllExport extern void
ChocolateLotStatePlugin_delete(struct PRESTypePlugin *);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* chocolate_factoryPlugin_1422893627_h */
