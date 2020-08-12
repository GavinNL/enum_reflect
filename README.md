# Enum Reflect

This is just an experiment to creating a simple reflection system for enum classes.


## Usage

Define an enum using the following system

```C++
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
// Note this include should be
#include "enum_reflect.inl"

```

You then have access to the following methods

```c++
# Converts the enum value into a string
std::string to_string(EnemyType);

# converts the string into the enum value
EnemyType from_string<EnemyType>(string)

# Returns a vector of all the enum values in the order
# defined
std::vector<EnemyValues> const& values<EnemyType>();
```
