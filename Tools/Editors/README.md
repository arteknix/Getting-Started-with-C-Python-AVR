# Text Editing

>[!IMPORTANT]
> It is important to have all parts of your code accessible and to be able to just type ONE COMMAND to build and upload your CODE.

Syntax highlighting is standard for Python / C / C++ / Makefiles.

## Software

### ViM (Vi Improved)
Once you have understood the _modal_ behaviour of ViM and memorized a few usefull commands, it's probably the one where you stay _closest to your project_.
This is the one I use (for many years now).

>[!TIP]
> The Tutorial comes with the packge and is available through the `vimtutor` command.\
> ViM has plugins and many useful features. One of my favourite features is completion of filenames (Cx-Cf) and of words already in your file (Cx-Cn).\
> The absolute killer is typing shell commands directly. And the one thing you will definately miss in most editors, is the **modeline**, indicating options your text-file wants/needs.\
> Example for Makefiles:
> `#vim: noexpandtab: ts=8: softtabstop=8 `

### KATE (Advanced Text Editor)
For people who want buttons or might be scared of making errors in a terminal.\
This is the first one I used when discovering Linux.\
It has many features and plugins, file navigator and integrated terminal.\
If you activate the **build plugin**, you can define rules to use. (cf. Makefiles).\
Kate's code-completion is extensive.
