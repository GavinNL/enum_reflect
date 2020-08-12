#include <iostream>
#include <cassert>

// these should be included before you create your enums
#include <string>
#include <vector>


//================================================================
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
//================================================================



//================================================================
// Set the name of the enum
#define ENUM_DEFINE    EnemyType

// Set the base type
#define ENUM_BASE_TYPE int32_t

// Set the label/values
#define ENUM_DEFINE_VALUES \
    ENUM_VALUE( MONSTER,      1)\
    ENUM_VALUE( HUMANOID,     2)\
    ENUM_VALUE( KRAKEN,       3)

// include this inline header to generate the relection
// classes/functions
namespace myNameSpace
{
// create the enum in a namespace
#include "enum_reflect.inl"
}

//===============================================================


int main(int argc, char ** argv)
{
    // loop through all the values in the enum and convert it to a string
    for(auto & x : values<MyEnum>())
    {
        std::cout << to_string(x) << " = " << static_cast<int32_t>(x) << std::endl;
    }

    // convert the string values back into enums
    assert( from_string<MyEnum>("VALUE_A") == MyEnum::VALUE_A);
    assert( from_string<MyEnum>("VALUE_B") == MyEnum::VALUE_B);
    assert( from_string<MyEnum>("VALUE_C") == MyEnum::VALUE_C);



    // loop through all the values in the enum and convert it to a string
    for(auto & x : myNameSpace::values<myNameSpace::EnemyType>())
    {
        std::cout << myNameSpace::to_string(x) << " = " << static_cast<int32_t>(x) << std::endl;
    }

    // convert the string values back into enums
    assert( myNameSpace::from_string<myNameSpace::EnemyType>("MONSTER") == myNameSpace::EnemyType::MONSTER);
    assert( myNameSpace::from_string<myNameSpace::EnemyType>("HUMANOID") == myNameSpace::EnemyType::HUMANOID);
    assert( myNameSpace::from_string<myNameSpace::EnemyType>("KRAKEN") == myNameSpace::EnemyType::KRAKEN);

    return 0;
}
