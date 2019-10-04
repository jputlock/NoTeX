# NoTeX
NoTeX is a lightweight TeX editor made for Computer Science and Mathematics students. With a focus on fast and intuitive note-taking, NoTeX provides students with a way to visually see the TeX they are writing. It is written in C++, linking with the project [pdf2svg](https://github.com/dawbarton/pdf2svg) to create Scalable Vector Graphics (SVGs) to allow resizing of individual LaTeX components. The GUI is written in GTKmm, a C++ API for GTK.

## Development
Interested in development? Great! Below are a set of instructions to quick start you into the development process. You can also join the [Discord](https://discord.gg/wGJrKBz) for communicating with other developers.

### Dependencies
The project has dependencies on:
NoTeX also takes advantage of the following open source projects:

- [pdf2svg](https://github.com/dawbarton/pdf2svg)

### Installation and Setup

1. [Fork the repository](https://help.github.com/en/articles/fork-a-repo#fork-an-example-repository).

2. [Clone the repository](https://help.github.com/en/articles/cloning-a-repository) onto your machine.

3. Navigate into your cloned repository and create a `build` folder.

4. Install the required dependencies:
- [gtkmm](https://www.gtkmm.org/)
- [cairo](https://www.cairographics.org/)
- [popperglib](https://poppler.freedesktop.org/)

Note that installation instructions of these dependencies may differ between operating systems.

5. Navigate into your `build` directory and make the project using `cmake ..; make`.

6. Run with `./NoTeX`

### Sharing your Contributions

1. Write your code into your local clone of your fork.

2. Commit and push your changes to your fork.

3. Go to the [main repository](https://github.com/team-notex/NoTeX).

4. Click the "Pull Requests" tab.

5. Create a pull request. If you are unfamiliar, follow [these instructions](https://help.github.com/en/articles/creating-a-pull-request-from-a-fork).

