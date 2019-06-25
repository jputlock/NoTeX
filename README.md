# NoTeX
NoTeX is a lightweight TeX editor made for Computer Science and Mathematics students. With a focus on fast and intuitive note-taking, NoTeX provides students with a way to visually see the TeX they are writing. It is written in C++, linking with the project [pdf2svg](https://github.com/dawbarton/pdf2svg) to create Scalable Vector Graphics (SVGs) to allow resizing of individual LaTeX components. The GUI is written in GTKmm, a C++ API for GTK.

## Milestones:

1. June 28th - Created a line of communication between developers.

2. July 12th - Finalizing the choices in data structure for overlaying text and images with a partial (or complete!) implementation. Have looked into GTK, played around with it, and looked at how to create streamlined GTK development.

3. July 19th - Finish basic GUI that allows for text editing / saving, as well as inserting and resizing images.

4. July 26th - _At least_ started integration between images and text to lead into the core feature of the platform.

5. August 2nd - Working integration between images and text, clipboard usage, redo/undo.

6. August 9th - Working demo with image/text integration, clipboard usage, redo/undo, saving and loading, and possibly other features?

7. August 23rd - More polished GUI + cleaner runtimes and ensuring documentation is there.

## Development
Interested in development? Great! Below are a set of instructions to quick start you into the development process! You can also join the [Discord](https://discord.gg/wGJrKBz) for communicating with other developers!

### Quick Setup

1. [Fork the repository](https://help.github.com/en/articles/fork-a-repo#fork-an-example-repository).

2. [Clone the repository](https://help.github.com/en/articles/cloning-a-repository) onto your machine.

3. Create a `build` folder.

4. Build by changing directory into `build` and run `cmake ..; make`.

5. Run with `./NoTeX`

### Sharing your Contributions

1. Go to the [main repository](https://github.com/team-notex/NoTeX).

2. Click the "Pull Requests" tab.

3. Follow [these instructions](https://help.github.com/en/articles/creating-a-pull-request-from-a-fork).
