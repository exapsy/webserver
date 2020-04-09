# Custom webserver

This is a project to understand how webservers work by making my very own one.

## USAGE

```bash
# Make a `build` directory inside repository
mkdir build
cd build

# Build makefiles via cmake inside build directory
cmake .. .

# Compile project
make

# Run webserver
./webserver # Default port 3000
./webserver 3005 # Runs webserver at port 3005
```

Go to your web browser.
Go to http://locahost:3000 - or whatever port you assigned in
