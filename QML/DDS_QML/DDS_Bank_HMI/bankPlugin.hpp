

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from bank.idl
using RTI Code Generator (rtiddsgen) version 3.1.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef bankPlugin_1860238704_h
#define bankPlugin_1860238704_h

#include "bank.hpp"

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

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern unsigned int 
OperationKindPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern unsigned int 
OperationKindPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
OperationKindPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* ----------------------------------------------------------------------------
Support functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern void
OperationKindPluginSupport_print_data(
    const OperationKind *sample, const char *desc, int indent_level);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern unsigned int 
FundKindPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern unsigned int 
FundKindPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
FundKindPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* ----------------------------------------------------------------------------
Support functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern void
FundKindPluginSupport_print_data(
    const FundKind *sample, const char *desc, int indent_level);

/* The type used to store keys for instances of type struct
* AnotherSimple.
*
* By default, this type is struct Transaction
* itself. However, if for some reason this choice is not practical for your
* system (e.g. if sizeof(struct Transaction)
* is very large), you may redefine this typedef in terms of another type of
* your choosing. HOWEVER, if you define the KeyHolder type to be something
* other than struct AnotherSimple, the
* following restriction applies: the key of struct
* Transaction must consist of a
* single field of your redefined KeyHolder type and that field must be the
* first field in struct Transaction.
*/
typedef  class Transaction TransactionKeyHolder;

#define TransactionPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define TransactionPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define TransactionPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define TransactionPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
#define TransactionPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

#define TransactionPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define TransactionPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern Transaction*
TransactionPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern Transaction*
TransactionPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern Transaction*
TransactionPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
TransactionPluginSupport_copy_data(
    Transaction *out,
    const Transaction *in);

NDDSUSERDllExport extern void 
TransactionPluginSupport_destroy_data_w_params(
    Transaction *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
TransactionPluginSupport_destroy_data_ex(
    Transaction *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
TransactionPluginSupport_destroy_data(
    Transaction *sample);

NDDSUSERDllExport extern void 
TransactionPluginSupport_print_data(
    const Transaction *sample,
    const char *desc,
    unsigned int indent);

NDDSUSERDllExport extern Transaction*
TransactionPluginSupport_create_key_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern Transaction*
TransactionPluginSupport_create_key(void);

NDDSUSERDllExport extern void 
TransactionPluginSupport_destroy_key_ex(
    TransactionKeyHolder *key,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
TransactionPluginSupport_destroy_key(
    TransactionKeyHolder *key);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
TransactionPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
TransactionPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
TransactionPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
TransactionPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
TransactionPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    Transaction *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
TransactionPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    Transaction *out,
    const Transaction *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
TransactionPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const Transaction *sample,
    ::dds::core::policy::DataRepresentationId representation
    = ::dds::core::policy::DataRepresentation::xcdr()); 

NDDSUSERDllExport extern RTIBool 
TransactionPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    Transaction **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
TransactionPlugin_deserialize_from_cdr_buffer(
    Transaction *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern unsigned int 
TransactionPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
TransactionPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
TransactionPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
TransactionPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
TransactionPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    Transaction ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
TransactionPlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    TransactionKeyHolder *key, 
    const Transaction *instance);

NDDSUSERDllExport extern RTIBool 
TransactionPlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    Transaction *instance, 
    const TransactionKeyHolder *key);

NDDSUSERDllExport extern RTIBool 
TransactionPlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos); 

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
TransactionPlugin_new(void);

NDDSUSERDllExport extern void
TransactionPlugin_delete(struct PRESTypePlugin *);

#define ResetPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define ResetPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define ResetPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define ResetPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define ResetPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern Reset*
ResetPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern Reset*
ResetPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern Reset*
ResetPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
ResetPluginSupport_copy_data(
    Reset *out,
    const Reset *in);

NDDSUSERDllExport extern void 
ResetPluginSupport_destroy_data_w_params(
    Reset *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
ResetPluginSupport_destroy_data_ex(
    Reset *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
ResetPluginSupport_destroy_data(
    Reset *sample);

NDDSUSERDllExport extern void 
ResetPluginSupport_print_data(
    const Reset *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
ResetPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
ResetPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
ResetPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
ResetPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
ResetPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    Reset *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
ResetPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    Reset *out,
    const Reset *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
ResetPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const Reset *sample,
    ::dds::core::policy::DataRepresentationId representation
    = ::dds::core::policy::DataRepresentation::xcdr()); 

NDDSUSERDllExport extern RTIBool 
ResetPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    Reset **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
ResetPlugin_deserialize_from_cdr_buffer(
    Reset *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern unsigned int 
ResetPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
ResetPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
ResetPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
ResetPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
ResetPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    Reset ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
ResetPlugin_new(void);

NDDSUSERDllExport extern void
ResetPlugin_delete(struct PRESTypePlugin *);

/* The type used to store keys for instances of type struct
* AnotherSimple.
*
* By default, this type is struct ResultTransaction
* itself. However, if for some reason this choice is not practical for your
* system (e.g. if sizeof(struct ResultTransaction)
* is very large), you may redefine this typedef in terms of another type of
* your choosing. HOWEVER, if you define the KeyHolder type to be something
* other than struct AnotherSimple, the
* following restriction applies: the key of struct
* ResultTransaction must consist of a
* single field of your redefined KeyHolder type and that field must be the
* first field in struct ResultTransaction.
*/
typedef  class ResultTransaction ResultTransactionKeyHolder;

#define ResultTransactionPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define ResultTransactionPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define ResultTransactionPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define ResultTransactionPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
#define ResultTransactionPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

#define ResultTransactionPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define ResultTransactionPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern ResultTransaction*
ResultTransactionPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern ResultTransaction*
ResultTransactionPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern ResultTransaction*
ResultTransactionPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
ResultTransactionPluginSupport_copy_data(
    ResultTransaction *out,
    const ResultTransaction *in);

NDDSUSERDllExport extern void 
ResultTransactionPluginSupport_destroy_data_w_params(
    ResultTransaction *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
ResultTransactionPluginSupport_destroy_data_ex(
    ResultTransaction *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
ResultTransactionPluginSupport_destroy_data(
    ResultTransaction *sample);

NDDSUSERDllExport extern void 
ResultTransactionPluginSupport_print_data(
    const ResultTransaction *sample,
    const char *desc,
    unsigned int indent);

NDDSUSERDllExport extern ResultTransaction*
ResultTransactionPluginSupport_create_key_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern ResultTransaction*
ResultTransactionPluginSupport_create_key(void);

NDDSUSERDllExport extern void 
ResultTransactionPluginSupport_destroy_key_ex(
    ResultTransactionKeyHolder *key,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
ResultTransactionPluginSupport_destroy_key(
    ResultTransactionKeyHolder *key);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
ResultTransactionPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
ResultTransactionPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
ResultTransactionPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
ResultTransactionPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
ResultTransactionPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    ResultTransaction *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
ResultTransactionPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    ResultTransaction *out,
    const ResultTransaction *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
ResultTransactionPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const ResultTransaction *sample,
    ::dds::core::policy::DataRepresentationId representation
    = ::dds::core::policy::DataRepresentation::xcdr()); 

NDDSUSERDllExport extern RTIBool 
ResultTransactionPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    ResultTransaction **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
ResultTransactionPlugin_deserialize_from_cdr_buffer(
    ResultTransaction *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern unsigned int 
ResultTransactionPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
ResultTransactionPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
ResultTransactionPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
ResultTransactionPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
ResultTransactionPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    ResultTransaction ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
ResultTransactionPlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    ResultTransactionKeyHolder *key, 
    const ResultTransaction *instance);

NDDSUSERDllExport extern RTIBool 
ResultTransactionPlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    ResultTransaction *instance, 
    const ResultTransactionKeyHolder *key);

NDDSUSERDllExport extern RTIBool 
ResultTransactionPlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos); 

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
ResultTransactionPlugin_new(void);

NDDSUSERDllExport extern void
ResultTransactionPlugin_delete(struct PRESTypePlugin *);

#define HelloWorldPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define HelloWorldPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define HelloWorldPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define HelloWorldPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define HelloWorldPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern HelloWorld*
HelloWorldPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern HelloWorld*
HelloWorldPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern HelloWorld*
HelloWorldPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
HelloWorldPluginSupport_copy_data(
    HelloWorld *out,
    const HelloWorld *in);

NDDSUSERDllExport extern void 
HelloWorldPluginSupport_destroy_data_w_params(
    HelloWorld *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
HelloWorldPluginSupport_destroy_data_ex(
    HelloWorld *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
HelloWorldPluginSupport_destroy_data(
    HelloWorld *sample);

NDDSUSERDllExport extern void 
HelloWorldPluginSupport_print_data(
    const HelloWorld *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
HelloWorldPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
HelloWorldPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
HelloWorldPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
HelloWorldPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
HelloWorldPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    HelloWorld *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
HelloWorldPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    HelloWorld *out,
    const HelloWorld *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
HelloWorldPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const HelloWorld *sample,
    ::dds::core::policy::DataRepresentationId representation
    = ::dds::core::policy::DataRepresentation::xcdr()); 

NDDSUSERDllExport extern RTIBool 
HelloWorldPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    HelloWorld **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
HelloWorldPlugin_deserialize_from_cdr_buffer(
    HelloWorld *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern unsigned int 
HelloWorldPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
HelloWorldPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
HelloWorldPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
HelloWorldPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
HelloWorldPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    HelloWorld ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
HelloWorldPlugin_new(void);

NDDSUSERDllExport extern void
HelloWorldPlugin_delete(struct PRESTypePlugin *);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* bankPlugin_1860238704_h */

