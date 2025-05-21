#include <brisk/gui/Component.hpp>
#include <brisk/gui/GuiApplication.hpp>
#include <brisk/widgets/Graphene.hpp>
#include <brisk/widgets/Button.hpp>
#include <brisk/widgets/Layouts.hpp>
#include <brisk/widgets/Text.hpp>

using namespace Brisk;

// Root component of the application, inherits from Brisk's Component class
class RootComponent : public Component {
public:
    // Builds the UI layout for the component
    Rc<Widget> build() final {
        return rcnew VLayout{
            stylesheet = Graphene::stylesheet(), // Apply the default stylesheet
            Graphene::darkColors(),              // Use dark color scheme
            gapRow = 8_px,                       // Set vertical gap between elements
            alignItems = AlignItems::Center,     // Align child widgets to the center
            justifyContent = Justify::Center,    // Center the layout in the parent
            rcnew Text{"Hello, world"},          // Display a text widget with "Hello, world"
            rcnew Button{
                rcnew Text{"Quit"},              // Button label
                onClick = lifetime() | []() {    // Quit the application on button click
                    windowApplication->quit();
                },
            },
        };
    }
};

// Entry point of the Brisk application
int briskMain() {
    GuiApplication application; // Create the GUI application
    return application.run(createComponent<RootComponent>()); // Run with RootComponent as main component
}
