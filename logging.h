#ifndef BUSE_LOGGING_INCLUDED
#define BUSE_LOGGING_INCLUDED

#define LOG(f_) if (((struct config *)userdata) -> verbose) { fprintf(stderr, (f_ "\n")); }

#define LOGF(f_, ...) if (((struct config *)userdata) -> verbose) { fprintf(stderr, (f_ "\n"), ##__VA_ARGS__); }

#endif /* BUSE_LOGGING_INCLUDED */
