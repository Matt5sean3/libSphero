# List the source files

# Options for swig bindings

OPTION(PYTHON_SWIG "Compile SWIG Python bindings" ON)
#OPTION(TCL_SWIG "Compile Tcl bindings" ON)
#OPTION(PERL_SWIG "Compile Perl bindings" ON)
#OPTION(GUILE_SWIG "Compile Guile bindings" ON)
#OPTION(JAVA_SWIG "Compile Java bindings" ON)
#OPTION(RUBY_SWIG "Compile Ruby bindings" ON)
#OPTION(MZSCHEME_SWIG "Compile Mzscheme bindings" ON)
#OPTION(PHP_SWIG "Compile PHP bindings" ON)
#OPTION(CAML_SWIG "Compile Ocaml bindings" ON)
#OPTION(PIKE_SWIG "Compile Pike bindings" ON)
#OPTION(CSHARP_SWIG "Compile C# bindings" ON)
#OPTION(ALLEGROCL_SWIG "Compile Allegro CL bindings" ON)
#OPTION(MODULA3_SWIG "Compile Modula-3 bindings" ON)
#OPTION(LUA_SWIG "Compile Lua bindings" ON)
#OPTION(CLISP_SWIG "Compile CLISP bindings" ON)
#OPTION(UFFI_SWIG "Compile Common Lisp with UFFI bindings" ON)
#OPTION(CFFI_SWIG "Compile Common Lisp with CFFI bindings" ON)
#OPTION(R_SWIG "Compile R bindings" ON)
#OPTION(OCTAVE_SWIG "Compile Octave bindings" ON)
#OPTION(GO_SWIG "Compile Go bindings" ON)
#OPTION(D_SWIG "Compile D bindings" ON)
#OPTION(JAVASCRIPT_SWIG "Compile Javascript bindings" ON)

# Generate swig bindings for various languages

SET(SWIG_SOURCE_FILE ${PROJECT_SOURCE_DIR}/sphero.i)

IF(PYTHON_SWIG)
ADD_SUBDIRECTORY(Python)
ENDIF(PYTHON_SWIG)

