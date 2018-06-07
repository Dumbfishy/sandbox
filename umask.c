#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

main()
{
   mode_t oldMask, newMask;

      /* Get old mask, temporarily setting the mask to 0.             */
   oldMask = umask((mode_t) 0);

      /* Print old mask. Octal values are used by mask.               */
   printf("Old mask = %on\n", (int) oldMask);

   system("touch file1");
      /* Make sure group read permission is allowed.                  */
   if (oldMask & S_IRGRP) {
      printf("Changing group read permission from MASKED to UNMASKED.n\n");
      oldMask = (oldMask ^ S_IRGRP);
   }
      /* Make sure group write and execute permission is not allowed. */
   //newMask = (oldMask|S_IWGRP|S_IXGRP);
   //newMask = (~0 | S_IRWXU | S_IRWXG | S_IRWXO);
    newMask = 0777;

   umask(~newMask);                                /* Update mask.     */
   printf("New mask = %onn\n", (int) newMask);    /* Print new mask.  */

    system("touch file2");

   printf("The file mode creation mask now specifies:nn\n");
   printf("     Group read permission      UNMASKEDn\n");
   printf("     Group write permission     MASKEDn\n");
   printf("     Group execute permission   MASKEDn\n");
}

