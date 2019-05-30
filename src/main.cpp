#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <string>

/*

*/
int create_svg(char* tex_to_compile, char* file_out){
    int pid = fork();

    // child
    if (pid == 0){
        char* args[] = {(char*)"pdflatex", (char*)"-interaction=nonstopmode", (char*)"-halt-on-error", tex_to_compile, NULL};

        // call PDFLatex to compile into a standalone PDF
        execvp(args[0], args);

        return EXIT_SUCCESS;

    }
    int status;

    // wait until the PDF is compiled
    waitpid(pid, &status, 0);

    pid = fork();
    if (pid == 0){

        char* pdf_name = (char*)"standalone.pdf";

        char* args[] = {(char*)"pdf2svg", pdf_name, file_out, NULL};

        // Convert PDF to SVG file
        execvp(args[0], args);

        return EXIT_SUCCESS;
    }

    // Wait for the SVG to be generated
    waitpid(pid, &status, 0);

    pid = fork();
    if(pid == 0){

        char* args[] = {(char*)"rm", (char*)"standalone.aux", (char*)"standalone.pdf", (char*)"standalone.log", NULL};
        execvp(args[0], args);

        return EXIT_SUCCESS;
    }

    std::cout << "Operation finished. See \"" << file_out << "\"" << std::endl;

    return EXIT_SUCCESS;
}

int main(int argc, char** argv) {

    char* tex = (char*)"\\documentclass{standalone}\\usepackage{amsmath}\\begin{document} $\\dfrac{x}{y+3}$ \\end{document}";

    char* file_out;
    int exit_code;
    if (argc == 2){
        file_out = argv[1];
        exit_code = create_svg(tex, file_out);
    } else {
        exit_code = create_svg(tex, (char*)"new.svg");
    }

    std::cout << "Function create_svg() exited with code: " << exit_code << std::endl;

    return 0;
}
