
#include <gtkmm.h>

#include "editorapp.h"
#include "CompileConfig.h"

int main(int argc, char** argv) {

    std::cout << "NoTeX version " << NoTeX_VERSION_MAJOR << "."
                                            << NoTeX_VERSION_MINOR << std::endl;

    Gtk::Main kit(argc, argv);

    auto application = EditorApplication::create();

    const int status = application->run(argc, argv);
    std::cout << status << std::endl;
//  return status;

    /*
    char* file_out;
    int exit_code;

    char* tex = (char*)"\\documentclass{standalone}\\usepackage{amsmath}\\begin{document} $\\dfrac{x}{y+3}$ \\end{document}";

    // "\documentclass{standalone}\usepackage{amsmath}\\begin{document} $\dfrac{x}{y+3}$ \end{document}"

    if (argc == 2){
        file_out = argv[1];
        exit_code = create_svg(tex, file_out);
    } else {
        exit_code = create_svg(tex, (char*)"new.svg");
    }

    std::cout << "Function create_svg() exited with code: " << exit_code << std::endl;
    */

    return 0;
}
