
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <gtkmm.h>

#include "Editor.h"
#include "CompileConfig.h"
#include "include/pdf2svg/pdf2svg.c"

/** @brief Converts a string of TeX into an SVG at file denoted by string
 * file_out.
 *
 * @param tex_to_compile - the TeX to compile in char* format.
 * @param file_out - the path to where the SVG file should be saved.
 *
 * The TeX is converted into a pdf via PDFLatex and then converted from PDF
 * to SVG via the open source PDF to SVG converter, pdf2svg.
 *
 * @return the exit code denoting whether or not it was successful.
 *
 */

int create_svg(char* tex_to_compile, char* file_out){
    int pid = fork();

    // child
    if (pid == 0){
        char* args[] = {(char*)"pdflatex", (char*)"-interaction=nonstopmode", (char*)"-halt-on-error", tex_to_compile, NULL};

        // call PDFLatex to compile into a standalone PDF
        int exit_code = execvp(args[0], args);

        return exit_code;

    }
    int status;

    // wait until the PDF is compiled
    waitpid(pid, &status, 0);
    if (status == -1){
        perror("PDF compilation failed");
        return status;
    }

    char* pdf_name = (char*)"standalone.pdf";

    char* args[] = {(char*)"pdf2svg", pdf_name, file_out, NULL};

    int exit_code = pdf2svg(3, args);

    // Wait for the SVG to be generated
    waitpid(pid, &status, 0);
    if (status == -1){
        perror("SVG generation failed");
        return status;
    }

    pid = fork();
    if(pid == 0){

        char* args[] = {(char*)"rm", (char*)"standalone.aux", (char*)"standalone.pdf", (char*)"standalone.log", NULL};
        int exit_code = execvp(args[0], args);

        return exit_code;
    }

    std::cout << "Operation finished. See \"" << file_out << "\"" << std::endl;

    return EXIT_SUCCESS;
}

int main(int argc, char** argv) {

    // auto app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");

    // Editor editor;
    // editor.set_default_size(200, 200);

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

    // return app->run(editor);

    return 0;
}
