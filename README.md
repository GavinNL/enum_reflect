# Enum Reflect

This is just an experiment to creating a simple reflection system for enum classes.

In some of my projects, I need to convert from enums to json and back as well as being able to populate UI widgets with enum values (eg: combo boxes). It was becoming very annoying to handle all the case when there are lots of enums and lots of values. 

This simple method allows me to create a simple reflection system which can convert string <-> enum, as well as loop though all enum values.

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


