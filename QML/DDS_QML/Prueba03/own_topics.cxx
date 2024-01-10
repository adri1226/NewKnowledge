

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from own_topics.idl
using RTI Code Generator (rtiddsgen) version 3.1.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#include <iosfwd>
#include <iomanip>

#include "rti/topic/cdr/Serialization.hpp"

#include "own_topics.hpp"
#include "own_topicsPlugin.hpp"

#include <rti/util/ostream_operators.hpp>

// ---- OwnMessahe: 

OwnMessahe::OwnMessahe() :
    m_msg_ ("")  {
}   

OwnMessahe::OwnMessahe (
    const std::string& msg)
    :
        m_msg_( msg ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
OwnMessahe::OwnMessahe(OwnMessahe&& other_) OMG_NOEXCEPT  :m_msg_ (std::move(other_.m_msg_))
{
} 

OwnMessahe& OwnMessahe::operator=(OwnMessahe&&  other_) OMG_NOEXCEPT {
    OwnMessahe tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void OwnMessahe::swap(OwnMessahe& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_msg_, other_.m_msg_);
}  

bool OwnMessahe::operator == (const OwnMessahe& other_) const {
    if (m_msg_ != other_.m_msg_) {
        return false;
    }
    return true;
}
bool OwnMessahe::operator != (const OwnMessahe& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const OwnMessahe& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "msg: " << sample.msg() ;
    o <<"]";
    return o;
}

// --- Type traits: -------------------------------------------------

namespace rti { 
    namespace topic {

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct native_type_code< OwnMessahe > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode OwnMessahe_g_tc_msg_string;

                static DDS_TypeCode_Member OwnMessahe_g_tc_members[1]=
                {

                    {
                        (char *)"msg",/* Member name */
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
                    }
                };

                static DDS_TypeCode OwnMessahe_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"OwnMessahe", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        OwnMessahe_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for OwnMessahe*/

                if (is_initialized) {
                    return &OwnMessahe_g_tc;
                }

                OwnMessahe_g_tc_msg_string = initialize_string_typecode((256L));

                OwnMessahe_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                OwnMessahe_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&OwnMessahe_g_tc_msg_string;

                /* Initialize the values for member annotations. */
                OwnMessahe_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                OwnMessahe_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                OwnMessahe_g_tc._data._sampleAccessInfo = sample_access_info();
                OwnMessahe_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &OwnMessahe_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                OwnMessahe *sample;

                static RTIXCdrMemberAccessInfo OwnMessahe_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo OwnMessahe_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &OwnMessahe_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    OwnMessahe);
                if (sample == NULL) {
                    return NULL;
                }

                OwnMessahe_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->msg() - (char *)sample);

                OwnMessahe_g_sampleAccessInfo.memberAccessInfos = 
                OwnMessahe_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(OwnMessahe);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        OwnMessahe_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        OwnMessahe_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                OwnMessahe_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                OwnMessahe_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< OwnMessahe >;

                OwnMessahe_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &OwnMessahe_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin OwnMessahe_g_typePlugin = 
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

                return &OwnMessahe_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< OwnMessahe >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< OwnMessahe >::get())));
        }

    }
}

namespace dds { 
    namespace topic {
        void topic_type_support< OwnMessahe >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                OwnMessahePlugin_new,
                OwnMessahePlugin_delete);
        }

        std::vector<char>& topic_type_support< OwnMessahe >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const OwnMessahe& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = OwnMessahePlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = OwnMessahePlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< OwnMessahe >::from_cdr_buffer(OwnMessahe& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = OwnMessahePlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create OwnMessahe from cdr buffer");
        }

        void topic_type_support< OwnMessahe >::reset_sample(OwnMessahe& sample) 
        {
            sample.msg("");
        }

        void topic_type_support< OwnMessahe >::allocate_sample(OwnMessahe& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.msg(),  -1, 256L);
        }

    }
}  

