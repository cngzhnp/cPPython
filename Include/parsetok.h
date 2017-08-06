/* Parser-tokenizer link interface */
#ifndef Py_LIMITED_API
#ifndef Py_PARSETOK_H
#define Py_PARSETOK_H

class PErrDetail
{
private:
    int error;
#ifndef PGEN
    /* The filename is useless for pgen, see comment in tok_state structure */
    PyObject *filename;
#endif
    int lineno;
    int offset;
    char *text;                 /* UTF-8-encoded string */
    int token;
    int expected;

public:
    int initialize(PyObject *);
    void setError(int p_error) { error = p_error; }
    PyObject* getFilename() const { return filename; }
    void setFilename(PyObject *p_filename) { filename = p_filename; }
};

#if 0
#define PyPARSE_YIELD_IS_KEYWORD	0x0001
#endif

#define PyPARSE_DONT_IMPLY_DEDENT	0x0002

#if 0
#define PyPARSE_WITH_IS_KEYWORD		0x0003
#define PyPARSE_PRINT_IS_FUNCTION       0x0004
#define PyPARSE_UNICODE_LITERALS        0x0008
#endif

#define PyPARSE_IGNORE_COOKIE 0x0010
#define PyPARSE_BARRY_AS_BDFL 0x0020

PyAPI_FUNC(node *) PyParser_ParseString(const char *, grammar *, int, PErrDetail *);

PyAPI_FUNC(node *) PyParser_ParseFile (FILE *, const char *, grammar *, int, const char *, const char *, PErrDetail *, int flags = 0);

PyAPI_FUNC(node *) PyParser_ParseFileFlags(FILE *, const char *, const char *, grammar *, int, const char *, const char *, PErrDetail *, int);

PyAPI_FUNC(node *) PyParser_ParseFileFlagsEx(FILE *, const char *, const char *, grammar *, int, const char *, const char *, PErrDetail *, int *);

PyAPI_FUNC(node *) PyParser_ParseFileObject(FILE *, PyObject *, const char *, grammar *, int, const char *, const char *, PErrDetail *, int *);

PyAPI_FUNC(node *) PyParser_ParseStringFlagsFilename(const char *, const char *, grammar *, int, PErrDetail *, int);

PyAPI_FUNC(node *) PyParser_ParseStringFlagsFilenameEx(const char *, const char *, grammar *, int, PErrDetail *, int *);

PyAPI_FUNC(node *) PyParser_ParseStringObject(const char *s, PyObject *, grammar *, int, PErrDetail *, int *);

/* Note that the following functions are defined in pythonrun.c,
   not in parsetok.c */
PyAPI_FUNC(void) PyParser_SetError(PErrDetail *);
PyAPI_FUNC(void) PyParser_ClearError(PErrDetail *);

#endif /* !Py_PARSETOK_H */
#endif /* !Py_LIMITED_API */
