

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from bank.idl
using RTI Code Generator (rtiddsgen) version 3.1.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#include <iosfwd>
#include <iomanip>

#include "rti/topic/cdr/Serialization.hpp"

#include "bank.hpp"
#include "bankPlugin.hpp"

#include <rti/util/ostream_operators.hpp>

std::ostream& operator << (std::ostream& o,const OperationKind& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    switch(sample){
        case OperationKind::FUND:
        o << "OperationKind::FUND" << " ";
        break;
        case OperationKind::EXPENSE:
        o << "OperationKind::EXPENSE" << " ";
        break;
    }
    return o;
}

std::ostream& operator << (std::ostream& o,const FundKind& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    switch(sample){
        case FundKind::SAVINGS:
        o << "FundKind::SAVINGS" << " ";
        break;
        case FundKind::HOUSING:
        o << "FundKind::HOUSING" << " ";
        break;
        case FundKind::FOOD:
        o << "FundKind::FOOD" << " ";
        break;
        case FundKind::TRANSPORT:
        o << "FundKind::TRANSPORT" << " ";
        break;
        case FundKind::ENTRETAIMENT:
        o << "FundKind::ENTRETAIMENT" << " ";
        break;
        case FundKind::TRAVEL:
        o << "FundKind::TRAVEL" << " ";
        break;
        case FundKind::CLOTHING:
        o << "FundKind::CLOTHING" << " ";
        break;
        case FundKind::DEBTS:
        o << "FundKind::DEBTS" << " ";
        break;
    }
    return o;
}

// ---- Transaction: 

Transaction::Transaction() :
    m_fund_type_(FundKind::SAVINGS) ,
    m_operation_type_(OperationKind::FUND) ,
    m_amount_ (0)  {
}   

Transaction::Transaction (
    const FundKind& fund_type,
    const OperationKind& operation_type,
    int16_t amount)
    :
        m_fund_type_( fund_type ),
        m_operation_type_( operation_type ),
        m_amount_( amount ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
Transaction::Transaction(Transaction&& other_) OMG_NOEXCEPT  :m_fund_type_ (std::move(other_.m_fund_type_))
,
m_operation_type_ (std::move(other_.m_operation_type_))
,
m_amount_ (std::move(other_.m_amount_))
{
} 

Transaction& Transaction::operator=(Transaction&&  other_) OMG_NOEXCEPT {
    Transaction tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void Transaction::swap(Transaction& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_fund_type_, other_.m_fund_type_);
    swap(m_operation_type_, other_.m_operation_type_);
    swap(m_amount_, other_.m_amount_);
}  

bool Transaction::operator == (const Transaction& other_) const {
    if (m_fund_type_ != other_.m_fund_type_) {
        return false;
    }
    if (m_operation_type_ != other_.m_operation_type_) {
        return false;
    }
    if (m_amount_ != other_.m_amount_) {
        return false;
    }
    return true;
}
bool Transaction::operator != (const Transaction& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const Transaction& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "fund_type: " << sample.fund_type()<<", ";
    o << "operation_type: " << sample.operation_type()<<", ";
    o << "amount: " << sample.amount() ;
    o <<"]";
    return o;
}

// ---- Reset: 

Reset::Reset() :
    m_flag_ (0)  {
}   

Reset::Reset (
    bool flag)
    :
        m_flag_( flag ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
Reset::Reset(Reset&& other_) OMG_NOEXCEPT  :m_flag_ (std::move(other_.m_flag_))
{
} 

Reset& Reset::operator=(Reset&&  other_) OMG_NOEXCEPT {
    Reset tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void Reset::swap(Reset& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_flag_, other_.m_flag_);
}  

bool Reset::operator == (const Reset& other_) const {
    if (m_flag_ != other_.m_flag_) {
        return false;
    }
    return true;
}
bool Reset::operator != (const Reset& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const Reset& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "flag: " << sample.flag() ;
    o <<"]";
    return o;
}

// ---- ResultTransaction: 

ResultTransaction::ResultTransaction() :
    m_fund_type_(FundKind::SAVINGS) ,
    m_amount_ (0)  {
}   

ResultTransaction::ResultTransaction (
    const FundKind& fund_type,
    int16_t amount)
    :
        m_fund_type_( fund_type ),
        m_amount_( amount ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
ResultTransaction::ResultTransaction(ResultTransaction&& other_) OMG_NOEXCEPT  :m_fund_type_ (std::move(other_.m_fund_type_))
,
m_amount_ (std::move(other_.m_amount_))
{
} 

ResultTransaction& ResultTransaction::operator=(ResultTransaction&&  other_) OMG_NOEXCEPT {
    ResultTransaction tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void ResultTransaction::swap(ResultTransaction& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_fund_type_, other_.m_fund_type_);
    swap(m_amount_, other_.m_amount_);
}  

bool ResultTransaction::operator == (const ResultTransaction& other_) const {
    if (m_fund_type_ != other_.m_fund_type_) {
        return false;
    }
    if (m_amount_ != other_.m_amount_) {
        return false;
    }
    return true;
}
bool ResultTransaction::operator != (const ResultTransaction& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const ResultTransaction& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "fund_type: " << sample.fund_type()<<", ";
    o << "amount: " << sample.amount() ;
    o <<"]";
    return o;
}

// ---- HelloWorld: 

HelloWorld::HelloWorld() :
    m_msg_ ("")  {
}   

HelloWorld::HelloWorld (
    const std::string& msg)
    :
        m_msg_( msg ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
HelloWorld::HelloWorld(HelloWorld&& other_) OMG_NOEXCEPT  :m_msg_ (std::move(other_.m_msg_))
{
} 

HelloWorld& HelloWorld::operator=(HelloWorld&&  other_) OMG_NOEXCEPT {
    HelloWorld tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void HelloWorld::swap(HelloWorld& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_msg_, other_.m_msg_);
}  

bool HelloWorld::operator == (const HelloWorld& other_) const {
    if (m_msg_ != other_.m_msg_) {
        return false;
    }
    return true;
}
bool HelloWorld::operator != (const HelloWorld& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const HelloWorld& sample)
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
        const OperationKind default_enumerator<OperationKind>::value = OperationKind::FUND;
        template<>
        struct native_type_code< OperationKind > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member OperationKind_g_tc_members[2]=
                {

                    {
                        (char *)"FUND",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(OperationKind::FUND), 
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
                        (char *)"EXPENSE",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(OperationKind::EXPENSE), 
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

                static DDS_TypeCode OperationKind_g_tc =
                {{
                        DDS_TK_ENUM, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"OperationKind", /* Name */
                        NULL,     /* Base class type code is assigned later */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        OperationKind_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Type Modifier */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for OperationKind*/

                if (is_initialized) {
                    return &OperationKind_g_tc;
                }

                OperationKind_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                /* Initialize the values for annotations. */
                OperationKind_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                OperationKind_g_tc._data._annotations._defaultValue._u.long_value = 0;

                OperationKind_g_tc._data._sampleAccessInfo = sample_access_info();
                OperationKind_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &OperationKind_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo OperationKind_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo OperationKind_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &OperationKind_g_sampleAccessInfo;
                }

                OperationKind_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                OperationKind_g_sampleAccessInfo.memberAccessInfos = 
                OperationKind_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(OperationKind);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        OperationKind_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        OperationKind_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                OperationKind_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                OperationKind_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< OperationKind >;

                OperationKind_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &OperationKind_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin OperationKind_g_typePlugin = 
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

                return &OperationKind_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::EnumType& dynamic_type< OperationKind >::get()
        {
            return static_cast<const ::dds::core::xtypes::EnumType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< OperationKind >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE
        const FundKind default_enumerator<FundKind>::value = FundKind::SAVINGS;
        template<>
        struct native_type_code< FundKind > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member FundKind_g_tc_members[8]=
                {

                    {
                        (char *)"SAVINGS",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(FundKind::SAVINGS), 
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
                        (char *)"HOUSING",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(FundKind::HOUSING), 
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
                        (char *)"FOOD",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(FundKind::FOOD), 
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
                        (char *)"TRANSPORT",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(FundKind::TRANSPORT), 
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
                        (char *)"ENTRETAIMENT",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(FundKind::ENTRETAIMENT), 
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
                        (char *)"TRAVEL",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(FundKind::TRAVEL), 
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
                        (char *)"CLOTHING",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(FundKind::CLOTHING), 
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
                        (char *)"DEBTS",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(FundKind::DEBTS), 
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

                static DDS_TypeCode FundKind_g_tc =
                {{
                        DDS_TK_ENUM, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"FundKind", /* Name */
                        NULL,     /* Base class type code is assigned later */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        8, /* Number of members */
                        FundKind_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Type Modifier */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for FundKind*/

                if (is_initialized) {
                    return &FundKind_g_tc;
                }

                FundKind_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                /* Initialize the values for annotations. */
                FundKind_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                FundKind_g_tc._data._annotations._defaultValue._u.long_value = 0;

                FundKind_g_tc._data._sampleAccessInfo = sample_access_info();
                FundKind_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &FundKind_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo FundKind_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo FundKind_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &FundKind_g_sampleAccessInfo;
                }

                FundKind_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                FundKind_g_sampleAccessInfo.memberAccessInfos = 
                FundKind_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(FundKind);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        FundKind_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        FundKind_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                FundKind_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                FundKind_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< FundKind >;

                FundKind_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &FundKind_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin FundKind_g_typePlugin = 
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

                return &FundKind_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::EnumType& dynamic_type< FundKind >::get()
        {
            return static_cast<const ::dds::core::xtypes::EnumType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< FundKind >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct native_type_code< Transaction > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member Transaction_g_tc_members[3]=
                {

                    {
                        (char *)"fund_type",/* Member name */
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
                        RTI_CDR_KEY_MEMBER , /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"operation_type",/* Member name */
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
                    }, 
                    {
                        (char *)"amount",/* Member name */
                        {
                            2,/* Representation ID */
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

                static DDS_TypeCode Transaction_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"Transaction", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        Transaction_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for Transaction*/

                if (is_initialized) {
                    return &Transaction_g_tc;
                }

                Transaction_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                Transaction_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< FundKind>::get().native();
                Transaction_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< OperationKind>::get().native();
                Transaction_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;

                /* Initialize the values for member annotations. */
                Transaction_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                Transaction_g_tc_members[0]._annotations._defaultValue._u.enumerated_value = 0;

                Transaction_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                Transaction_g_tc_members[1]._annotations._defaultValue._u.enumerated_value = 0;

                Transaction_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_SHORT;
                Transaction_g_tc_members[2]._annotations._defaultValue._u.short_value = 0;
                Transaction_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_SHORT;
                Transaction_g_tc_members[2]._annotations._minValue._u.short_value = RTIXCdrShort_MIN;
                Transaction_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_SHORT;
                Transaction_g_tc_members[2]._annotations._maxValue._u.short_value = RTIXCdrShort_MAX;

                Transaction_g_tc._data._sampleAccessInfo = sample_access_info();
                Transaction_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &Transaction_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                Transaction *sample;

                static RTIXCdrMemberAccessInfo Transaction_g_memberAccessInfos[3] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo Transaction_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &Transaction_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    Transaction);
                if (sample == NULL) {
                    return NULL;
                }

                Transaction_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->fund_type() - (char *)sample);

                Transaction_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->operation_type() - (char *)sample);

                Transaction_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->amount() - (char *)sample);

                Transaction_g_sampleAccessInfo.memberAccessInfos = 
                Transaction_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(Transaction);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        Transaction_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        Transaction_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                Transaction_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                Transaction_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< Transaction >;

                Transaction_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &Transaction_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin Transaction_g_typePlugin = 
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

                return &Transaction_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< Transaction >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< Transaction >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct native_type_code< Reset > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member Reset_g_tc_members[1]=
                {

                    {
                        (char *)"flag",/* Member name */
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

                static DDS_TypeCode Reset_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"Reset", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        Reset_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for Reset*/

                if (is_initialized) {
                    return &Reset_g_tc;
                }

                Reset_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                Reset_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::interpreter::initialize_bool_typecode();

                /* Initialize the values for member annotations. */
                Reset_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_BOOLEAN;
                Reset_g_tc_members[0]._annotations._defaultValue._u.boolean_value = 0;

                Reset_g_tc._data._sampleAccessInfo = sample_access_info();
                Reset_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &Reset_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                Reset *sample;

                static RTIXCdrMemberAccessInfo Reset_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo Reset_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &Reset_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    Reset);
                if (sample == NULL) {
                    return NULL;
                }

                Reset_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->flag() - (char *)sample);

                Reset_g_sampleAccessInfo.memberAccessInfos = 
                Reset_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(Reset);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        Reset_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        Reset_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                Reset_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                Reset_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< Reset >;

                Reset_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &Reset_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin Reset_g_typePlugin = 
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

                return &Reset_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< Reset >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< Reset >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct native_type_code< ResultTransaction > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member ResultTransaction_g_tc_members[2]=
                {

                    {
                        (char *)"fund_type",/* Member name */
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
                        RTI_CDR_KEY_MEMBER , /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"amount",/* Member name */
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

                static DDS_TypeCode ResultTransaction_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"ResultTransaction", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        ResultTransaction_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for ResultTransaction*/

                if (is_initialized) {
                    return &ResultTransaction_g_tc;
                }

                ResultTransaction_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                ResultTransaction_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< FundKind>::get().native();
                ResultTransaction_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;

                /* Initialize the values for member annotations. */
                ResultTransaction_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                ResultTransaction_g_tc_members[0]._annotations._defaultValue._u.enumerated_value = 0;

                ResultTransaction_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_SHORT;
                ResultTransaction_g_tc_members[1]._annotations._defaultValue._u.short_value = 0;
                ResultTransaction_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_SHORT;
                ResultTransaction_g_tc_members[1]._annotations._minValue._u.short_value = RTIXCdrShort_MIN;
                ResultTransaction_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_SHORT;
                ResultTransaction_g_tc_members[1]._annotations._maxValue._u.short_value = RTIXCdrShort_MAX;

                ResultTransaction_g_tc._data._sampleAccessInfo = sample_access_info();
                ResultTransaction_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &ResultTransaction_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ResultTransaction *sample;

                static RTIXCdrMemberAccessInfo ResultTransaction_g_memberAccessInfos[2] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo ResultTransaction_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &ResultTransaction_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ResultTransaction);
                if (sample == NULL) {
                    return NULL;
                }

                ResultTransaction_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->fund_type() - (char *)sample);

                ResultTransaction_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->amount() - (char *)sample);

                ResultTransaction_g_sampleAccessInfo.memberAccessInfos = 
                ResultTransaction_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(ResultTransaction);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        ResultTransaction_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        ResultTransaction_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                ResultTransaction_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                ResultTransaction_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ResultTransaction >;

                ResultTransaction_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &ResultTransaction_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin ResultTransaction_g_typePlugin = 
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

                return &ResultTransaction_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< ResultTransaction >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ResultTransaction >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct native_type_code< HelloWorld > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode HelloWorld_g_tc_msg_string;

                static DDS_TypeCode_Member HelloWorld_g_tc_members[1]=
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

                static DDS_TypeCode HelloWorld_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"HelloWorld", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        HelloWorld_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for HelloWorld*/

                if (is_initialized) {
                    return &HelloWorld_g_tc;
                }

                HelloWorld_g_tc_msg_string = initialize_string_typecode((256L));

                HelloWorld_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                HelloWorld_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&HelloWorld_g_tc_msg_string;

                /* Initialize the values for member annotations. */
                HelloWorld_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                HelloWorld_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                HelloWorld_g_tc._data._sampleAccessInfo = sample_access_info();
                HelloWorld_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &HelloWorld_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                HelloWorld *sample;

                static RTIXCdrMemberAccessInfo HelloWorld_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo HelloWorld_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &HelloWorld_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    HelloWorld);
                if (sample == NULL) {
                    return NULL;
                }

                HelloWorld_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->msg() - (char *)sample);

                HelloWorld_g_sampleAccessInfo.memberAccessInfos = 
                HelloWorld_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(HelloWorld);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        HelloWorld_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        HelloWorld_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                HelloWorld_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                HelloWorld_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< HelloWorld >;

                HelloWorld_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &HelloWorld_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin HelloWorld_g_typePlugin = 
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

                return &HelloWorld_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< HelloWorld >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< HelloWorld >::get())));
        }

    }
}

namespace dds { 
    namespace topic {
        void topic_type_support< Transaction >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                TransactionPlugin_new,
                TransactionPlugin_delete);
        }

        std::vector<char>& topic_type_support< Transaction >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const Transaction& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = TransactionPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = TransactionPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< Transaction >::from_cdr_buffer(Transaction& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = TransactionPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create Transaction from cdr buffer");
        }

        void topic_type_support< Transaction >::reset_sample(Transaction& sample) 
        {
            sample.fund_type(FundKind::SAVINGS);
            sample.operation_type(OperationKind::FUND);
            sample.amount(0);
        }

        void topic_type_support< Transaction >::allocate_sample(Transaction& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.fund_type(),  -1, -1);
            ::rti::topic::allocate_sample(sample.operation_type(),  -1, -1);
        }

        void topic_type_support< Reset >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ResetPlugin_new,
                ResetPlugin_delete);
        }

        std::vector<char>& topic_type_support< Reset >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const Reset& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = ResetPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = ResetPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< Reset >::from_cdr_buffer(Reset& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = ResetPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create Reset from cdr buffer");
        }

        void topic_type_support< Reset >::reset_sample(Reset& sample) 
        {
            sample.flag(0);
        }

        void topic_type_support< Reset >::allocate_sample(Reset& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample);
        }

        void topic_type_support< ResultTransaction >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ResultTransactionPlugin_new,
                ResultTransactionPlugin_delete);
        }

        std::vector<char>& topic_type_support< ResultTransaction >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ResultTransaction& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = ResultTransactionPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = ResultTransactionPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ResultTransaction >::from_cdr_buffer(ResultTransaction& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = ResultTransactionPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ResultTransaction from cdr buffer");
        }

        void topic_type_support< ResultTransaction >::reset_sample(ResultTransaction& sample) 
        {
            sample.fund_type(FundKind::SAVINGS);
            sample.amount(0);
        }

        void topic_type_support< ResultTransaction >::allocate_sample(ResultTransaction& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.fund_type(),  -1, -1);
        }

        void topic_type_support< HelloWorld >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                HelloWorldPlugin_new,
                HelloWorldPlugin_delete);
        }

        std::vector<char>& topic_type_support< HelloWorld >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const HelloWorld& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = HelloWorldPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = HelloWorldPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< HelloWorld >::from_cdr_buffer(HelloWorld& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = HelloWorldPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create HelloWorld from cdr buffer");
        }

        void topic_type_support< HelloWorld >::reset_sample(HelloWorld& sample) 
        {
            sample.msg("");
        }

        void topic_type_support< HelloWorld >::allocate_sample(HelloWorld& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.msg(),  -1, 256L);
        }

    }
}  

