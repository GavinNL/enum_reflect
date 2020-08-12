/*===================================================================
Example Usage
===================================================================

// Set the name of the enum
#define ENUM_DEFINE    MyEnum

// Set the base type
#define ENUM_BASE_TYPE int32_t

// Set the label/values
#define ENUM_DEFINE_VALUES \
    ENUM_VALUE( VALUE_A,      1)\
    ENUM_VALUE( VALUE_B,      2)\
    ENUM_VALUE( VALUE_C,      3)

// include this inline header to generate the relection
// classes/functions
#include "enum_reflect.inl"

===================================================================*/

template<typename T>
T from_string(const std::string & S);

template<typename T>
std::vector<T> const & values();


enum class ENUM_DEFINE : ENUM_BASE_TYPE
{
    #define ENUM_VALUE(A, V) A = V,
    ENUM_DEFINE_VALUES
    #undef ENUM_VALUE
};

template<>
inline std::vector<ENUM_DEFINE> const & values()
{
    static std::vector<ENUM_DEFINE> values = std::vector<ENUM_DEFINE>();
    if( values.size() == 0)
    {
        #define ENUM_VALUE(A, V) values.push_back(ENUM_DEFINE::A);
        ENUM_DEFINE_VALUES
        #undef ENUM_VALUE
    };
    return values;
}


template<>
inline ENUM_DEFINE from_string(const std::string & s)
{
    #define ENUM_VALUE(A, V) if( s == #A ) return ENUM_DEFINE::A;
    ENUM_DEFINE_VALUES
    #undef ENUM_VALUE
    throw std::runtime_error("Unknown value");
}

inline std::string to_string(ENUM_DEFINE v)
{
    switch( v )
    {
        #define ENUM_VALUE(A, V) case ENUM_DEFINE::A: return std::string( #A );
        ENUM_DEFINE_VALUES
        #undef ENUM_VALUE
    }
    return "";
}

#undef ENUM_DEFINE
#undef ENUM_BASE_TYPE
#undef ENUM_DEFINE_VALUES
