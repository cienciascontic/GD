/** \file This file contains some common tools which can be used in source file and in C++ Code events of Game Develop projects.
*
* This file is automatically included by Game Develop. See GDL/EventsPrecompiledHeader.h for a full list of automatically
* included files.
 */
//Extensions writers: Please do not use these functions: There are meant to be used
//for ease the writing

#include <vector>
#include "GDL/RuntimeObject.h"

/**
 * Returns a vector containing only the objects of type T.
 *
 * \param objectsList A vector containing pointers to objects.
 * \return A vector containing only the objects of type T.
 */
template<typename T>
std::vector<T*> GetSpecificObjects( const std::vector<RuntimeObject*> & objectsList )
{
    std::vector<T*> specializedObjects;
    specializedObjects.reserve(objectsList.size());

    for (unsigned int i = 0;i<objectsList.size();++i)
    {
        T * specializedObject = dynamic_cast<T*>(objectsList[i]);
        if ( specializedObject != NULL ) specializedObjects.push_back(specializedObject);
    }

    return specializedObjects;
}