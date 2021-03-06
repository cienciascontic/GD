/**

GDevelop - Draggable Behavior Extension
Copyright (c) 2014-2016 Florian Rival (Florian.Rival@gmail.com)
This project is released under the MIT License.
*/

#include "GDCpp/Extensions/ExtensionBase.h"

#include "DraggableBehavior.h"


void DeclareDraggableBehaviorExtension(gd::PlatformExtension & extension)
{
    extension.SetExtensionInformation("DraggableBehavior",
                              _("Draggable Behavior"),
                              _("This Extension enables the movement of objects with a mouse."),
                              "Florian Rival",
                              "Open source (MIT License)");

    gd::BehaviorMetadata & aut = extension.AddBehavior("Draggable",
          _("Draggable object"),
          _("Draggable"),
          _("Allows objects to be moved using the mouse."),
          "",
          "CppPlatform/Extensions/draggableicon.png",
          "DraggableBehavior",
          std::make_shared<DraggableBehavior>(),
          std::shared_ptr<gd::BehaviorsSharedData>());

    #if defined(GD_IDE_ONLY)
    aut.SetIncludeFile("DraggableBehavior/DraggableBehavior.h");

    aut.AddCondition("Dragged",
                   _("Being dragged"),
                   _("Check if the object is being dragged"),
                   _("_PARAM0_ is being dragged"),
                   _(""),
                   "CppPlatform/Extensions/draggableicon24.png",
                   "CppPlatform/Extensions/draggableicon16.png")

        .AddParameter("object", _("Object"))
        .AddParameter("behavior", _("Behavior"), "Draggable")

        .SetFunctionName("IsDragged").SetIncludeFile("DraggableBehavior/DraggableBehavior.h");
    #endif

}

/**
 * \brief This class declares information about the extension.
 */
class Extension : public ExtensionBase
{
public:

    /**
     * Constructor of an extension declares everything the extension contains: objects, actions, conditions and expressions.
     */
    Extension()
    {
        DeclareDraggableBehaviorExtension(*this);
        GD_COMPLETE_EXTENSION_COMPILATION_INFORMATION();
    };
};

#if !defined(EMSCRIPTEN)
/**
 * Used by GDevelop to create the extension class
 * -- Do not need to be modified. --
 */
extern "C" ExtensionBase * GD_EXTENSION_API CreateGDExtension() {
    return new Extension;
}
#endif
