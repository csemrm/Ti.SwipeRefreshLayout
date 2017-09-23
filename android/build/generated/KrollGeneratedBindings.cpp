/* C++ code produced by gperf version 3.0.3 */
/* Command-line: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/gperf -L C++ -E -t /Users/ingrowth/Documents/Projects/Ti.SwipeRefreshLayout/android/build/generated/KrollGeneratedBindings.gperf  */
/* Computed positions: -k'' */

#line 3 "/Users/ingrowth/Documents/Projects/Ti.SwipeRefreshLayout/android/build/generated/KrollGeneratedBindings.gperf"


#include <string.h>
#include <v8.h>
#include <KrollBindings.h>

#include "com.rkam.swiperefreshlayout.SwiperefreshlayoutModule.h"
#include "com.rkam.swiperefreshlayout.SwipeRefreshProxy.h"


namespace titanium {
namespace bindings {
#line 16 "/Users/ingrowth/Documents/Projects/Ti.SwipeRefreshLayout/android/build/generated/KrollGeneratedBindings.gperf"
struct BindEntry;
/* maximum key range = 8, duplicates = 0 */

class SwiperefreshlayoutBindings
{
private:
  static inline unsigned int hash (const char *str, unsigned int len);
public:
  static struct BindEntry *lookupGeneratedInit (const char *str, unsigned int len);
};

inline /*ARGSUSED*/
unsigned int
SwiperefreshlayoutBindings::hash (register const char *str, register unsigned int len)
{
  return len;
}

struct BindEntry *
SwiperefreshlayoutBindings::lookupGeneratedInit (register const char *str, register unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 2,
      MIN_WORD_LENGTH = 45,
      MAX_WORD_LENGTH = 52,
      MIN_HASH_VALUE = 45,
      MAX_HASH_VALUE = 52
    };

  static struct BindEntry wordlist[] =
    {
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 18 "/Users/ingrowth/Documents/Projects/Ti.SwipeRefreshLayout/android/build/generated/KrollGeneratedBindings.gperf"
      {"com.rkam.swiperefreshlayout.SwipeRefreshProxy",::com::rkam::swiperefreshlayout::swiperefreshlayout::SwipeRefreshProxy::bindProxy,::com::rkam::swiperefreshlayout::swiperefreshlayout::SwipeRefreshProxy::dispose},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 19 "/Users/ingrowth/Documents/Projects/Ti.SwipeRefreshLayout/android/build/generated/KrollGeneratedBindings.gperf"
      {"com.rkam.swiperefreshlayout.SwiperefreshlayoutModule",::com::rkam::swiperefreshlayout::SwiperefreshlayoutModule::bindProxy,::com::rkam::swiperefreshlayout::SwiperefreshlayoutModule::dispose}
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      unsigned int key = hash (str, len);

      if (key <= MAX_HASH_VALUE)
        {
          register const char *s = wordlist[key].name;

          if (*str == *s && !strcmp (str + 1, s + 1))
            return &wordlist[key];
        }
    }
  return 0;
}
#line 20 "/Users/ingrowth/Documents/Projects/Ti.SwipeRefreshLayout/android/build/generated/KrollGeneratedBindings.gperf"

}
}
