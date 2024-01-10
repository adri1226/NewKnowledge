

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from own_topics.idl
using RTI Code Generator (rtiddsgen) version 3.1.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef own_topicsPlugin_746979369_h
#define own_topicsPlugin_746979369_h

#include "own_topics.hpp"

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

#define OwnMessahePlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define OwnMessahePlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define OwnMessahePlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define OwnMessahePlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define OwnMessahePlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern OwnMessahe*
OwnMessahePluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern OwnMessahe*
OwnMessahePluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern OwnMessahe*
OwnMessahePluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
OwnMessahePluginSupport_copy_data(
    OwnMessahe *out,
    const OwnMessahe *in);

NDDSUSERDllExport extern void 
OwnMessahePluginSupport_destroy_data_w_params(
    OwnMessahe *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
OwnMessahePluginSupport_destroy_data_ex(
    OwnMessahe *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
OwnMessahePluginSupport_destroy_data(
    OwnMessahe *sample);

NDDSUSERDllExport extern void 
OwnMessahePluginSupport_print_data(
    const OwnMessahe *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
OwnMessahePlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
OwnMessahePlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
OwnMessahePlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
OwnMessahePlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
OwnMessahePlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    OwnMessahe *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
OwnMessahePlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    OwnMessahe *out,
    const OwnMessahe *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
OwnMessahePlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const OwnMessahe *sample,
    ::dds::core::policy::DataRepresentationId representation
    = ::dds::core::policy::DataRepresentation::xcdr()); 

NDDSUSERDllExport extern RTIBool 
OwnMessahePlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    OwnMessahe **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
OwnMessahePlugin_deserialize_from_cdr_buffer(
    OwnMessahe *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern unsigned int 
OwnMessahePlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
OwnMessahePlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
OwnMessahePlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
OwnMessahePlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
OwnMessahePlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    OwnMessahe ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
OwnMessahePlugin_new(void);

NDDSUSERDllExport extern void
OwnMessahePlugin_delete(struct PRESTypePlugin *);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* own_topicsPlugin_746979369_h */

