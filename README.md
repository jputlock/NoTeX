# NoTeX
NoTeX is a lightweight TeX editor made for Computer Science and Mathematics students. With a focus on fast and intuitive note-taking, NoTeX provides students with a way to visually see the TeX they are writing. It is written in C++, linking with the project [pdf2svg](https://github.com/dawbarton/pdf2svg) to create Scalable Vector Graphics (SVGs) to allow resizing of individual LaTeX components. The GUI is written in GTKmm, a C++ API for GTK.


## Installation and Setup

1. [Clone the repository](https://help.github.com/en/articles/cloning-a-repository) onto your machine.

2. Navigate into your cloned repository and create a `build` folder.

3. Install the required dependencies:
- [gtkmm](https://www.gtkmm.org/)
- [cairo](https://www.cairographics.org/)
- [popperglib](https://poppler.freedesktop.org/)
- [cmake](https://cmake.org/)
- [LaTeX](https://www.latex-project.org/)

Note that installation instructions of these dependencies may differ between operating systems.

4. Navigate into your `build` directory and make the project using `cmake ..; make`.

5. Run with `./NoTeX`


## Development
Interested in development? Great! Below are a set of instructions to quick start you into the development process. You can also join the [Discord](https://discord.gg/wGJrKBz) for communicating with other developers.

1. [Fork the repository](https://help.github.com/en/articles/fork-a-repo#fork-an-example-repository).

2. [Clone your forked repository](https://help.github.com/en/articles/cloning-a-repository) onto your machine.

3. Navigate into your cloned repository and create a `build` folder.

4. On top of the required dependencies listed above, you will also need:
- [clang](https://clang.llvm.org/)

5. Navigate into your `build` directory and make the project using `cmake ..; make`.

6. Run with `./NoTeX`

### Sharing your Contributions
Before submitting your code, make sure to check the [Contribution Guidelines](CONTRIBUTING.md).

1. Write your code into your local clone of your fork.

2. Commit and push your changes to your fork.

3. Go to the [main repository](https://github.com/team-notex/NoTeX) and create a pull request. If you are unfamiliar, click on the "Pull Requests" tab and follow [these instructions](https://help.github.com/en/articles/creating-a-pull-request-from-a-fork).
