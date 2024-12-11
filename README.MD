# Cross-platform Raylib Template
This is a basic template for raylib projects that compiles to multiple platforms

| Host Platform | Native Support | HTML 5 Support |
| ------------- | -------------- | -------------- |
| Windows       | Supported      | Soon           |
| Linux         | Supported      | Soon           |
| MacOS         | Untested       | Unsupported    |
| RPi           | Untested       | Unsupported    |
| RPi Desktop   | Untested       | Unsupported    |
| Android       | Untested       | Unsupported    |

## Using the template

### Method 1 (Preferred): Github template
To create a repository on GitHub from a template, see [this link](https://docs.github.com/en/repositories/creating-and-managing-repositories/creating-a-repository-from-a-template#creating-a-repository-from-a-template)

### Method 2: Cloning
Clone the template, with submodules

```
REPO_NAME=<name>
&& git clone --recurse-submodules https://github.com/rfblock/raylib-xplatform-template.git $REPO_NAME
&& cd $REPO_NAME/src
```

Remove remote origin
```
git remote remove origin
```

Build raylib
```
make raylib
```

Build and run the example project
```
make run
```

### General Use
#### Make commands
| Command         | Effect                                         |
| --------------- | ---------------------------------------------- |
| `make build`    | Builds the project                             |
| `make run`      | Builds and runs the project                    |
| `make raylib`   | Cleans and builds raylib for the host platform |
| `make clean`    | Cleans objects                                 |
| `make cleanall` | Cleans objects and build targets               |