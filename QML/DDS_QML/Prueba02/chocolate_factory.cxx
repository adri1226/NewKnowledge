

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from chocolate_factory.idl
using RTI Code Generator (rtiddsgen) version 3.1.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#include <iosfwd>
#include <iomanip>

#include "rti/topic/cdr/Serialization.hpp"

#include "chocolate_factory.hpp"
#include "chocolate_factoryPlugin.hpp"

#include <rti/util/ostream_operators.hpp>

// ---- Temperature:

Temperature::Temperature() :
    m_sensor_id_ ("") ,
    m_degrees_ (0)  {
}

Temperature::Temperature (
    const std::string& sensor_id,
    int32_t degrees)
    :
        m_sensor_id_( sensor_id ),
        m_degrees_( degrees ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
Temperature::Temperature(Temperature&& other_) OMG_NOEXCEPT  :m_sensor_id_ (std::move(other_.m_sensor_id_))
,
m_degrees_ (std::move(other_.m_degrees_))
{
}

Temperature& Temperature::operator=(Temperature&&  other_) OMG_NOEXCEPT {
    Temperature tmp(std::move(other_));
    swap(tmp);
    return *this;
}
#endif
#endif

void Temperature::swap(Temperature& other_)  OMG_NOEXCEPT
{
    using std::swap;
    swap(m_sensor_id_, other_.m_sensor_id_);
    swap(m_degrees_, other_.m_degrees_);
}

bool Temperature::operator == (const Temperature& other_) const {
    if (m_sensor_id_ != other_.m_sensor_id_) {
        return false;
    }
    if (m_degrees_ != other_.m_degrees_) {
        return false;
    }
    return true;
}
bool Temperature::operator != (const Temperature& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const Temperature& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "sensor_id: " << sample.sensor_id()<<", ";
    o << "degrees: " << sample.degrees() ;
    o <<"]";
    return o;
}

std::ostream& operator << (std::ostream& o,const LotStatusKind& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    switch(sample){
        case LotStatusKind::WAITING:
        o << "LotStatusKind::WAITING" << " ";
        break;
        case LotStatusKind::PROCESSING:
        o << "LotStatusKind::PROCESSING" << " ";
        break;
        case LotStatusKind::COMPLETED:
        o << "LotStatusKind::COMPLETED" << " ";
        break;
    }
    return o;
}

// ---- ChocolateLotState:

ChocolateLotState::ChocolateLotState() :
    m_lot_id_ (0u) ,
    m_lot_status_(LotStatusKind::WAITING)  {
}

ChocolateLotState::ChocolateLotState (
    uint32_t lot_id,
    const LotStatusKind& lot_status)
    :
        m_lot_id_( lot_id ),
        m_lot_status_( lot_status ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
ChocolateLotState::ChocolateLotState(ChocolateLotState&& other_) OMG_NOEXCEPT  :m_lot_id_ (std::move(other_.m_lot_id_))
,
m_lot_status_ (std::move(other_.m_lot_status_))
{
}

ChocolateLotState& ChocolateLotState::operator=(ChocolateLotState&&  other_) OMG_NOEXCEPT {
    ChocolateLotState tmp(std::move(other_));
    swap(tmp);
    return *this;
}
#endif
#endif

void ChocolateLotState::swap(ChocolateLotState& other_)  OMG_NOEXCEPT
{
    using std::swap;
    swap(m_lot_id_, other_.m_lot_id_);
    swap(m_lot_status_, other_.m_lot_status_);
}

bool ChocolateLotState::operator == (const ChocolateLotState& other_) const {
    if (m_lot_id_ != other_.m_lot_id_) {
        return false;
    }
    if (m_lot_status_ != other_.m_lot_status_) {
        return false;
    }
    return true;
}
bool ChocolateLotState::operator != (const ChocolateLotState& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const ChocolateLotState& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "lot_id: " << sample.lot_id()<<", ";
    o << "lot_status: " << sample.lot_status() ;
    o <<"]";
    return o;
}

// --- Type traits: -------------------------------------------------

namespace rti {
    namespace topic {

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct native_type_code< Temperature > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode Temperature_g_tc_sensor_id_string;

                static DDS_TypeCode_Member Temperature_g_tc_members[2]=
                {

                    {
                        (char *)"sensor_id",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    },
                    {
                        (char *)"degrees",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode Temperature_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"Temperature", /* Name */
                        NULL, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        Temperature_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for Temperature*/

                if (is_initialized) {
                    return &Temperature_g_tc;
                }

                Temperature_g_tc_sensor_id_string = initialize_string_typecode((256L));

                Temperature_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                Temperature_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&Temperature_g_tc_sensor_id_string;
                Temperature_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

                /* Initialize the values for member annotations. */
                Temperature_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                Temperature_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                Temperature_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                Temperature_g_tc_members[1]._annotations._defaultValue._u.long_value = 0;
                Temperature_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                Temperature_g_tc_members[1]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                Temperature_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                Temperature_g_tc_members[1]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

                Temperature_g_tc._data._sampleAccessInfo = sample_access_info();
                Temperature_g_tc._data._typePlugin = type_plugin_info();

                is_initialized = RTI_TRUE;

                return &Temperature_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                Temperature *sample;

                static RTIXCdrMemberAccessInfo Temperature_g_memberAccessInfos[2] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo Temperature_g_sampleAccessInfo =
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &Temperature_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample,
                    Temperature);
                if (sample == NULL) {
                    return NULL;
                }

                Temperature_g_memberAccessInfos[0].bindingMemberValueOffset[0] =
                (RTIXCdrUnsignedLong) ((char *)&sample->sensor_id() - (char *)sample);

                Temperature_g_memberAccessInfos[1].bindingMemberValueOffset[0] =
                (RTIXCdrUnsignedLong) ((char *)&sample->degrees() - (char *)sample);

                Temperature_g_sampleAccessInfo.memberAccessInfos =
                Temperature_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(Temperature);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        Temperature_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        Temperature_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                Temperature_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                Temperature_g_sampleAccessInfo.getMemberValuePointerFcn =
                interpreter::get_aggregation_value_pointer< Temperature >;

                Temperature_g_sampleAccessInfo.languageBinding =
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &Temperature_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin Temperature_g_typePlugin =
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &Temperature_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< Temperature >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< Temperature >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE
        const LotStatusKind default_enumerator<LotStatusKind>::value = LotStatusKind::WAITING;
        template<>
        struct native_type_code< LotStatusKind > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member LotStatusKind_g_tc_members[3]=
                {

                    {
                        (char *)"WAITING",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(LotStatusKind::WAITING),
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    },
                    {
                        (char *)"PROCESSING",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(LotStatusKind::PROCESSING),
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    },
                    {
                        (char *)"COMPLETED",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(LotStatusKind::COMPLETED),
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode LotStatusKind_g_tc =
                {{
                        DDS_TK_ENUM, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"LotStatusKind", /* Name */
                        NULL,     /* Base class type code is assigned later */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        LotStatusKind_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Type Modifier */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for LotStatusKind*/

                if (is_initialized) {
                    return &LotStatusKind_g_tc;
                }

                LotStatusKind_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                /* Initialize the values for annotations. */
                LotStatusKind_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                LotStatusKind_g_tc._data._annotations._defaultValue._u.long_value = 0;

                LotStatusKind_g_tc._data._sampleAccessInfo = sample_access_info();
                LotStatusKind_g_tc._data._typePlugin = type_plugin_info();

                is_initialized = RTI_TRUE;

                return &LotStatusKind_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo LotStatusKind_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo LotStatusKind_g_sampleAccessInfo =
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &LotStatusKind_g_sampleAccessInfo;
                }

                LotStatusKind_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                LotStatusKind_g_sampleAccessInfo.memberAccessInfos =
                LotStatusKind_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(LotStatusKind);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        LotStatusKind_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        LotStatusKind_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                LotStatusKind_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                LotStatusKind_g_sampleAccessInfo.getMemberValuePointerFcn =
                interpreter::get_aggregation_value_pointer< LotStatusKind >;

                LotStatusKind_g_sampleAccessInfo.languageBinding =
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &LotStatusKind_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin LotStatusKind_g_typePlugin =
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &LotStatusKind_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::EnumType& dynamic_type< LotStatusKind >::get()
        {
            return static_cast<const ::dds::core::xtypes::EnumType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< LotStatusKind >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct native_type_code< ChocolateLotState > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member ChocolateLotState_g_tc_members[2]=
                {

                    {
                        (char *)"lot_id",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    },
                    {
                        (char *)"lot_status",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode ChocolateLotState_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"ChocolateLotState", /* Name */
                        NULL, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        ChocolateLotState_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for ChocolateLotState*/

                if (is_initialized) {
                    return &ChocolateLotState_g_tc;
                }

                ChocolateLotState_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                ChocolateLotState_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
                ChocolateLotState_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< LotStatusKind>::get().native();

                /* Initialize the values for member annotations. */
                ChocolateLotState_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_ULONG;
                ChocolateLotState_g_tc_members[0]._annotations._defaultValue._u.ulong_value = 0u;
                ChocolateLotState_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_ULONG;
                ChocolateLotState_g_tc_members[0]._annotations._minValue._u.ulong_value = RTIXCdrUnsignedLong_MIN;
                ChocolateLotState_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_ULONG;
                ChocolateLotState_g_tc_members[0]._annotations._maxValue._u.ulong_value = RTIXCdrUnsignedLong_MAX;

                ChocolateLotState_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                ChocolateLotState_g_tc_members[1]._annotations._defaultValue._u.enumerated_value = 0;

                ChocolateLotState_g_tc._data._sampleAccessInfo = sample_access_info();
                ChocolateLotState_g_tc._data._typePlugin = type_plugin_info();

                is_initialized = RTI_TRUE;

                return &ChocolateLotState_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ChocolateLotState *sample;

                static RTIXCdrMemberAccessInfo ChocolateLotState_g_memberAccessInfos[2] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo ChocolateLotState_g_sampleAccessInfo =
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &ChocolateLotState_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample,
                    ChocolateLotState);
                if (sample == NULL) {
                    return NULL;
                }

                ChocolateLotState_g_memberAccessInfos[0].bindingMemberValueOffset[0] =
                (RTIXCdrUnsignedLong) ((char *)&sample->lot_id() - (char *)sample);

                ChocolateLotState_g_memberAccessInfos[1].bindingMemberValueOffset[0] =
                (RTIXCdrUnsignedLong) ((char *)&sample->lot_status() - (char *)sample);

                ChocolateLotState_g_sampleAccessInfo.memberAccessInfos =
                ChocolateLotState_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(ChocolateLotState);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        ChocolateLotState_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        ChocolateLotState_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                ChocolateLotState_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                ChocolateLotState_g_sampleAccessInfo.getMemberValuePointerFcn =
                interpreter::get_aggregation_value_pointer< ChocolateLotState >;

                ChocolateLotState_g_sampleAccessInfo.languageBinding =
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &ChocolateLotState_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin ChocolateLotState_g_typePlugin =
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &ChocolateLotState_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< ChocolateLotState >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ChocolateLotState >::get())));
        }

    }
}

namespace dds {
    namespace topic {
        void topic_type_support< Temperature >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name)
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                TemperaturePlugin_new,
                TemperaturePlugin_delete);
        }

        std::vector<char>& topic_type_support< Temperature >::to_cdr_buffer(
            std::vector<char>& buffer,
            const Temperature& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = TemperaturePlugin_serialize_to_cdr_buffer(
                NULL,
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = TemperaturePlugin_serialize_to_cdr_buffer(
                &buffer[0],
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< Temperature >::from_cdr_buffer(Temperature& sample,
        const std::vector<char>& buffer)
        {

            RTIBool ok  = TemperaturePlugin_deserialize_from_cdr_buffer(
                &sample,
                &buffer[0],
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create Temperature from cdr buffer");
        }

        void topic_type_support< Temperature >::reset_sample(Temperature& sample)
        {
            sample.sensor_id("");
            sample.degrees(0);
        }

        void topic_type_support< Temperature >::allocate_sample(Temperature& sample, int, int)
        {
            ::rti::topic::allocate_sample(sample.sensor_id(),  -1, 256L);
        }

        void topic_type_support< ChocolateLotState >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name)
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ChocolateLotStatePlugin_new,
                ChocolateLotStatePlugin_delete);
        }

        std::vector<char>& topic_type_support< ChocolateLotState >::to_cdr_buffer(
            std::vector<char>& buffer,
            const ChocolateLotState& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = ChocolateLotStatePlugin_serialize_to_cdr_buffer(
                NULL,
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = ChocolateLotStatePlugin_serialize_to_cdr_buffer(
                &buffer[0],
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ChocolateLotState >::from_cdr_buffer(ChocolateLotState& sample,
        const std::vector<char>& buffer)
        {

            RTIBool ok  = ChocolateLotStatePlugin_deserialize_from_cdr_buffer(
                &sample,
                &buffer[0],
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ChocolateLotState from cdr buffer");
        }

        void topic_type_support< ChocolateLotState >::reset_sample(ChocolateLotState& sample)
        {
            sample.lot_id(0u);
            sample.lot_status(LotStatusKind::WAITING);
        }

        void topic_type_support< ChocolateLotState >::allocate_sample(ChocolateLotState& sample, int, int)
        {
            ::rti::topic::allocate_sample(sample.lot_status(),  -1, -1);
        }

    }
}
