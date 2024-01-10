

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from bank.idl
using RTI Code Generator (rtiddsgen) version 3.1.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef bank_1860238704_hpp
#define bank_1860238704_hpp

#include <iosfwd>

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport __declspec(dllexport)
#endif

#include "dds/domain/DomainParticipant.hpp"
#include "dds/topic/TopicTraits.hpp"
#include "dds/core/SafeEnumeration.hpp"
#include "dds/core/String.hpp"
#include "dds/core/array.hpp"
#include "dds/core/vector.hpp"
#include "dds/core/Optional.hpp"
#include "dds/core/xtypes/DynamicType.hpp"
#include "dds/core/xtypes/StructType.hpp"
#include "dds/core/xtypes/UnionType.hpp"
#include "dds/core/xtypes/EnumType.hpp"
#include "dds/core/xtypes/AliasType.hpp"
#include "rti/core/array.hpp"
#include "rti/core/BoundedSequence.hpp"
#include "rti/util/StreamFlagSaver.hpp"
#include "rti/domain/PluginSupport.hpp"
#include "rti/core/LongDouble.hpp"
#include "dds/core/External.hpp"
#include "rti/core/Pointer.hpp"
#include "rti/topic/TopicTraits.hpp"

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

static const std::string TRANSACTION_TOPIC = "Transaction";

static const std::string RESET_TOPIC = "Reset";

static const std::string RESULT_TRANSACTION_TOPIC = "ResultTransaction";
enum class OperationKind {
    FUND, 
    EXPENSE
};

NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const OperationKind& sample);
enum class FundKind {
    SAVINGS, 
    HOUSING, 
    FOOD, 
    TRANSPORT, 
    ENTRETAIMENT, 
    TRAVEL, 
    CLOTHING, 
    DEBTS
};

NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const FundKind& sample);

class NDDSUSERDllExport Transaction {
  public:
    Transaction();

    Transaction(
        const FundKind& fund_type,
        const OperationKind& operation_type,
        int16_t amount);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    Transaction (Transaction&&) = default;
    Transaction& operator=(Transaction&&) = default;
    Transaction& operator=(const Transaction&) = default;
    Transaction(const Transaction&) = default;
    #else
    Transaction(Transaction&& other_) OMG_NOEXCEPT;  
    Transaction& operator=(Transaction&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    FundKind& fund_type() OMG_NOEXCEPT {
        return m_fund_type_;
    }

    const FundKind& fund_type() const OMG_NOEXCEPT {
        return m_fund_type_;
    }

    void fund_type(const FundKind& value) {
        m_fund_type_ = value;
    }

    void fund_type(FundKind&& value) {
        m_fund_type_ = std::move(value);
    }
    OperationKind& operation_type() OMG_NOEXCEPT {
        return m_operation_type_;
    }

    const OperationKind& operation_type() const OMG_NOEXCEPT {
        return m_operation_type_;
    }

    void operation_type(const OperationKind& value) {
        m_operation_type_ = value;
    }

    void operation_type(OperationKind&& value) {
        m_operation_type_ = std::move(value);
    }
    int16_t& amount() OMG_NOEXCEPT {
        return m_amount_;
    }

    const int16_t& amount() const OMG_NOEXCEPT {
        return m_amount_;
    }

    void amount(int16_t value) {
        m_amount_ = value;
    }

    bool operator == (const Transaction& other_) const;
    bool operator != (const Transaction& other_) const;

    void swap(Transaction& other_) OMG_NOEXCEPT ;

  private:

    FundKind m_fund_type_;
    OperationKind m_operation_type_;
    int16_t m_amount_;

};

inline void swap(Transaction& a, Transaction& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const Transaction& sample);

class NDDSUSERDllExport Reset {
  public:
    Reset();

    explicit Reset(
        bool flag);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    Reset (Reset&&) = default;
    Reset& operator=(Reset&&) = default;
    Reset& operator=(const Reset&) = default;
    Reset(const Reset&) = default;
    #else
    Reset(Reset&& other_) OMG_NOEXCEPT;  
    Reset& operator=(Reset&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    bool& flag() OMG_NOEXCEPT {
        return m_flag_;
    }

    const bool& flag() const OMG_NOEXCEPT {
        return m_flag_;
    }

    void flag(bool value) {
        m_flag_ = value;
    }

    bool operator == (const Reset& other_) const;
    bool operator != (const Reset& other_) const;

    void swap(Reset& other_) OMG_NOEXCEPT ;

  private:

    bool m_flag_;

};

inline void swap(Reset& a, Reset& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const Reset& sample);

class NDDSUSERDllExport ResultTransaction {
  public:
    ResultTransaction();

    ResultTransaction(
        const FundKind& fund_type,
        int16_t amount);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    ResultTransaction (ResultTransaction&&) = default;
    ResultTransaction& operator=(ResultTransaction&&) = default;
    ResultTransaction& operator=(const ResultTransaction&) = default;
    ResultTransaction(const ResultTransaction&) = default;
    #else
    ResultTransaction(ResultTransaction&& other_) OMG_NOEXCEPT;  
    ResultTransaction& operator=(ResultTransaction&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    FundKind& fund_type() OMG_NOEXCEPT {
        return m_fund_type_;
    }

    const FundKind& fund_type() const OMG_NOEXCEPT {
        return m_fund_type_;
    }

    void fund_type(const FundKind& value) {
        m_fund_type_ = value;
    }

    void fund_type(FundKind&& value) {
        m_fund_type_ = std::move(value);
    }
    int16_t& amount() OMG_NOEXCEPT {
        return m_amount_;
    }

    const int16_t& amount() const OMG_NOEXCEPT {
        return m_amount_;
    }

    void amount(int16_t value) {
        m_amount_ = value;
    }

    bool operator == (const ResultTransaction& other_) const;
    bool operator != (const ResultTransaction& other_) const;

    void swap(ResultTransaction& other_) OMG_NOEXCEPT ;

  private:

    FundKind m_fund_type_;
    int16_t m_amount_;

};

inline void swap(ResultTransaction& a, ResultTransaction& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ResultTransaction& sample);

class NDDSUSERDllExport HelloWorld {
  public:
    HelloWorld();

    explicit HelloWorld(
        const std::string& msg);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    HelloWorld (HelloWorld&&) = default;
    HelloWorld& operator=(HelloWorld&&) = default;
    HelloWorld& operator=(const HelloWorld&) = default;
    HelloWorld(const HelloWorld&) = default;
    #else
    HelloWorld(HelloWorld&& other_) OMG_NOEXCEPT;  
    HelloWorld& operator=(HelloWorld&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    std::string& msg() OMG_NOEXCEPT {
        return m_msg_;
    }

    const std::string& msg() const OMG_NOEXCEPT {
        return m_msg_;
    }

    void msg(const std::string& value) {
        m_msg_ = value;
    }

    void msg(std::string&& value) {
        m_msg_ = std::move(value);
    }

    bool operator == (const HelloWorld& other_) const;
    bool operator != (const HelloWorld& other_) const;

    void swap(HelloWorld& other_) OMG_NOEXCEPT ;

  private:

    std::string m_msg_;

};

inline void swap(HelloWorld& a, HelloWorld& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const HelloWorld& sample);

namespace rti {
    namespace flat {
        namespace topic {
        }
    }
}
namespace dds {
    namespace topic {

        template<>
        struct topic_type_name< Transaction > {
            NDDSUSERDllExport static std::string value() {
                return "Transaction";
            }
        };

        template<>
        struct is_topic_type< Transaction > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< Transaction > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const Transaction& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(Transaction& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(Transaction& sample);

            NDDSUSERDllExport 
            static void allocate_sample(Transaction& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< Reset > {
            NDDSUSERDllExport static std::string value() {
                return "Reset";
            }
        };

        template<>
        struct is_topic_type< Reset > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< Reset > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const Reset& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(Reset& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(Reset& sample);

            NDDSUSERDllExport 
            static void allocate_sample(Reset& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< ResultTransaction > {
            NDDSUSERDllExport static std::string value() {
                return "ResultTransaction";
            }
        };

        template<>
        struct is_topic_type< ResultTransaction > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< ResultTransaction > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ResultTransaction& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(ResultTransaction& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(ResultTransaction& sample);

            NDDSUSERDllExport 
            static void allocate_sample(ResultTransaction& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< HelloWorld > {
            NDDSUSERDllExport static std::string value() {
                return "HelloWorld";
            }
        };

        template<>
        struct is_topic_type< HelloWorld > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< HelloWorld > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const HelloWorld& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(HelloWorld& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(HelloWorld& sample);

            NDDSUSERDllExport 
            static void allocate_sample(HelloWorld& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

    }
}

namespace rti { 
    namespace topic {

        #ifndef NDDS_STANDALONE_TYPE
        template <>
        struct default_enumerator<OperationKind>
        {
            static const OperationKind value;
        };
        template<>
        struct dynamic_type< OperationKind > {
            typedef ::dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::EnumType& get();
        };
        #endif

        template <>
        struct extensibility< OperationKind > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template <>
        struct default_enumerator<FundKind>
        {
            static const FundKind value;
        };
        template<>
        struct dynamic_type< FundKind > {
            typedef ::dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::EnumType& get();
        };
        #endif

        template <>
        struct extensibility< FundKind > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< Transaction > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< Transaction > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< Reset > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< Reset > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< ResultTransaction > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< ResultTransaction > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< HelloWorld > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< HelloWorld > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

    }
}

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif // bank_1860238704_hpp

