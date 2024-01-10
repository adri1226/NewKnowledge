/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from chocolate_factory.idl
using RTI Code Generator (rtiddsgen) version 3.1.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef chocolate_factory_1422893627_hpp
#define chocolate_factory_1422893627_hpp

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

class NDDSUSERDllExport Temperature {
  public:
    Temperature();

    Temperature(
        const std::string& sensor_id,
        int32_t degrees);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    Temperature (Temperature&&) = default;
    Temperature& operator=(Temperature&&) = default;
    Temperature& operator=(const Temperature&) = default;
    Temperature(const Temperature&) = default;
    #else
    Temperature(Temperature&& other_) OMG_NOEXCEPT;
    Temperature& operator=(Temperature&&  other_) OMG_NOEXCEPT;
    #endif
    #endif

    std::string& sensor_id() OMG_NOEXCEPT {
        return m_sensor_id_;
    }

    const std::string& sensor_id() const OMG_NOEXCEPT {
        return m_sensor_id_;
    }

    void sensor_id(const std::string& value) {
        m_sensor_id_ = value;
    }

    void sensor_id(std::string&& value) {
        m_sensor_id_ = std::move(value);
    }
    int32_t& degrees() OMG_NOEXCEPT {
        return m_degrees_;
    }

    const int32_t& degrees() const OMG_NOEXCEPT {
        return m_degrees_;
    }

    void degrees(int32_t value) {
        m_degrees_ = value;
    }

    bool operator == (const Temperature& other_) const;
    bool operator != (const Temperature& other_) const;

    void swap(Temperature& other_) OMG_NOEXCEPT ;

  private:

    std::string m_sensor_id_;
    int32_t m_degrees_;

};

inline void swap(Temperature& a, Temperature& b)  OMG_NOEXCEPT
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const Temperature& sample);

enum class LotStatusKind {
    WAITING,
    PROCESSING,
    COMPLETED
};

NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const LotStatusKind& sample);

class NDDSUSERDllExport ChocolateLotState {
  public:
    ChocolateLotState();

    ChocolateLotState(
        uint32_t lot_id,
        const LotStatusKind& lot_status);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    ChocolateLotState (ChocolateLotState&&) = default;
    ChocolateLotState& operator=(ChocolateLotState&&) = default;
    ChocolateLotState& operator=(const ChocolateLotState&) = default;
    ChocolateLotState(const ChocolateLotState&) = default;
    #else
    ChocolateLotState(ChocolateLotState&& other_) OMG_NOEXCEPT;
    ChocolateLotState& operator=(ChocolateLotState&&  other_) OMG_NOEXCEPT;
    #endif
    #endif

    uint32_t& lot_id() OMG_NOEXCEPT {
        return m_lot_id_;
    }

    const uint32_t& lot_id() const OMG_NOEXCEPT {
        return m_lot_id_;
    }

    void lot_id(uint32_t value) {
        m_lot_id_ = value;
    }

    LotStatusKind& lot_status() OMG_NOEXCEPT {
        return m_lot_status_;
    }

    const LotStatusKind& lot_status() const OMG_NOEXCEPT {
        return m_lot_status_;
    }

    void lot_status(const LotStatusKind& value) {
        m_lot_status_ = value;
    }

    void lot_status(LotStatusKind&& value) {
        m_lot_status_ = std::move(value);
    }

    bool operator == (const ChocolateLotState& other_) const;
    bool operator != (const ChocolateLotState& other_) const;

    void swap(ChocolateLotState& other_) OMG_NOEXCEPT ;

  private:

    uint32_t m_lot_id_;
    LotStatusKind m_lot_status_;

};

inline void swap(ChocolateLotState& a, ChocolateLotState& b)  OMG_NOEXCEPT
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ChocolateLotState& sample);

namespace rti {
    namespace flat {
        namespace topic {
        }
    }
}
namespace dds {
    namespace topic {

        template<>
        struct topic_type_name< Temperature > {
            NDDSUSERDllExport static std::string value() {
                return "Temperature";
            }
        };

        template<>
        struct is_topic_type< Temperature > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< Temperature > {
            NDDSUSERDllExport
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer,
                const Temperature& sample,
                ::dds::core::policy::DataRepresentationId representation
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport
            static void from_cdr_buffer(Temperature& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport
            static void reset_sample(Temperature& sample);

            NDDSUSERDllExport
            static void allocate_sample(Temperature& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind =
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< ChocolateLotState > {
            NDDSUSERDllExport static std::string value() {
                return "ChocolateLotState";
            }
        };

        template<>
        struct is_topic_type< ChocolateLotState > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< ChocolateLotState > {
            NDDSUSERDllExport
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer,
                const ChocolateLotState& sample,
                ::dds::core::policy::DataRepresentationId representation
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport
            static void from_cdr_buffer(ChocolateLotState& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport
            static void reset_sample(ChocolateLotState& sample);

            NDDSUSERDllExport
            static void allocate_sample(ChocolateLotState& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind =
            ::rti::topic::TypePluginKind::STL;
        };

    }
}

namespace rti {
    namespace topic {
        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< Temperature > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< Temperature > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;
        };

        #ifndef NDDS_STANDALONE_TYPE
        template <>
        struct default_enumerator<LotStatusKind>
        {
            static const LotStatusKind value;
        };
        template<>
        struct dynamic_type< LotStatusKind > {
            typedef ::dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::EnumType& get();
        };
        #endif

        template <>
        struct extensibility< LotStatusKind > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< ChocolateLotState > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< ChocolateLotState > {
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

#endif // chocolate_factory_1422893627_hpp
