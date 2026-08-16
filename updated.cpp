#include <iostream>
#include <string>          // needed for std::string
using namespace std;

// Modular exponentiation: computes (base^exp) % mod safely
// (avoids overflow and floating-point errors of pow())
long long binpow(long long base, long long exp, long long mod)
{
    base %= mod;
    long long result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

int main()
{
    cout << "enter the text:" << endl;
    string text;
    cin >> text;

    cout << "enter the pattern: " << endl;
    string pattern;
    cin >> pattern;

    // Edge cases that the original code did not handle
    if (pattern.empty())
    {
        cout << "empty pattern" << endl;
        return 0;
    }
    if (pattern.length() > text.length())
    {
        cout << "pattren not found" << endl;
        return 0;
    }

    const long long mod = 1e9 + 7;          // large prime modulus
    const int m = pattern.length();
    const int n = text.length();

    // h = 256^(m-1) % mod   (used to remove the leftmost character)
    long long h = binpow(256, m - 1, mod);

    // ---------- compute pattern hash and first window hash (Horner's method) ----------
    // This is simpler and safer than successive * inv256
    long long patternHash = 0;
    long long textHash = 0;
    for (int i = 0; i < m; i++)
    {
        patternHash = (patternHash * 256 + pattern[i]) % mod;
        textHash    = (textHash    * 256 + text[i])    % mod;
    }

    bool found = false;   // true if at least one real match occurred

    // Slide the window from left to right
    for (int i = 0; i <= n - m; i++)
    {
        // Hash values match → possible match (or collision)
        if (textHash == patternHash)
        {
            // Verify character-by-character to rule out collisions
            bool match = true;
            for (int j = 0; j < m; j++)
            {
                if (pattern[j] != text[i + j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                cout << "foundex : " << i << endl;
                found = true;
            }
        }

        // Compute hash of the next window (if there is a next window)
        if (i < n - m)
        {
            // Remove leftmost character, shift left, add new rightmost character
            // The "+ mod" guarantees a non-negative intermediate value
            textHash = (textHash - (text[i] * h) % mod + mod) % mod;
            textHash = (textHash * 256 + text[i + m]) % mod;
        }
    }

    if (!found)
        cout << "pattren not found" << endl;
    else
        cout << "pattren found" << endl;

    return 0;
}