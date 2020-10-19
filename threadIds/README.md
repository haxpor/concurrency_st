# threadId

Print platform specific thread id out from currently running thread.

# Windows

> **Warning**: The following block of paragraph is for x86 only.

We could make use of intrinsic function [__readfsdword](https://docs.microsoft.com/en-us/cpp/intrinsics/readfsbyte-readfsdword-readfsqword-readfsword?view=vs-2019)
but it's only available on x86 architecture also as tested with
AMD cpu, error of symbol not found shoted out. Listing of [TIB table](https://en.wikipedia.org/wiki/Win32_Thread_Information_Block)
for x86 which points out which offset to find such information.

---

Use [GetCurrentThreadId](https://docs.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-getcurrentthreadid)
to get thread id.

# Linux

Use [pthread_self](https://man7.org/linux/man-pages/man3/pthread_self.3.html).
