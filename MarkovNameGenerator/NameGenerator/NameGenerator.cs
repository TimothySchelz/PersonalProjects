using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NameGenerator
{
    /// <summary>
    /// A random name generator that uses a Markov process to generate the names
    /// </summary>
    public class NameGenerator
    {
        // A Dictionary to store the 
        private Dictionary<Char, Letter> letters;

        /// <summary>
        /// A constructor to create an instance of a name generator
        /// </summary>
        public NameGenerator()
        {
            letters = new Dictionary<char, Letter>();
            
            //Fill letters with letters
            for (int i = 65; i <= 90; i++)
            {
                Letter currentLetter = new Letter((char)i);
                letters.Add(currentLetter.Character, currentLetter);
            }
        }

        /// <summary>
        /// A constructor to create a name generator and automatically load in names.
        /// </summary>
        /// <param name="names">An IEnumerable of names to generate names with</param>
        public NameGenerator(IEnumerable<String> names)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// Load in names to be used to generate names with.
        /// </summary>
        /// <param name="names">names to be loaded in</param>
        public void LoadNames(IEnumerable<String> names)
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// Generates a random name based on the names loaded in.
        /// </summary>
        /// <returns></returns>
        public String GenerateName()
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// A private helper class to store all the info that goes along with each letter
        /// </summary>
        private class Letter
        {
            private Dictionary<Char, percent> percentages;
            Random rando = new Random();

            // The character that this letter represents
            public char Character
            {
                get;

                private set;
            }

            
            public Letter(char c)
            {
                Character = c;

                percentages = new Dictionary<char, decimal>();

                // Fill percentages with percentages.  Each letter starts with 0% chance.
                for (int i = 65; i <= 90; i++)
                {
                    percentages.Add((char)i, 0);
                }

                // the ending character starts with 100% chance of being the next character.
                percentages.Add('\n', 1);
            }

            public void addInstance()
            {

            }

            /// <summary>
            /// Returns what letter should come after this one.  Random based on the probability distribution of this letter.
            /// </summary>
            /// <returns>The next letter of the name</returns>
            public char NextLetter()
            {
                int randInt = rando.Next();
            }

            struct percent
            {
                private double percantage;
                private double total;
                private double events;
            }
        }
    }
}
