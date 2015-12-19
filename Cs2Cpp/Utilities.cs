using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Cs2Cpp
{
    static class Utilities
    {
        public static bool IsFilesystemCaseSensitive()
        {
            bool isCaseInsensitive;

            try
            {
                string file = Path.GetTempPath() + Guid.NewGuid().ToString().ToLower();
                File.CreateText(file).Close();
                isCaseInsensitive = File.Exists(file.ToUpper());
                File.Delete(file);
            }
            catch
            {
                throw new ApplicationException("Unable to determine case-sensitivity of filesystem.");
            }
            
            return isCaseInsensitive;
        }

        public static bool ArePathsToDirectoryEqual(string a, string b)
        {
            // TODO: Use  GetFileInformationByHandle() on windows for accurate results
            a = Path.GetFullPath(a);
            b = Path.GetFullPath(b);

            if (!IsFilesystemCaseSensitive())
            {
                a = a.ToLower();
                b = b.ToLower();
            }

            return a == b;
        }

        public static bool ArePathsToFileEqual(string a, string b)
        {
            // TODO: Use  GetFileInformationByHandle() on windows for accurate results
            a = Path.GetFullPath(a);
            b = Path.GetFullPath(b);

            if (!IsFilesystemCaseSensitive())
            {
                a = a.ToLower();
                b = b.ToLower();
            }

            return a == b;
        }
    }
}
