Markov Name Generator
by Timothy Schelz

	This is a name generator that uses a markov process to generate random names.  It can 
take in a list of names and then produce names similar to them.  The more names put in 
the better.  To use this name generator simply call LoadNames and give it a list and then 
call GenerateName to get a randomly generated name.

Implementation:
Name Generator has a dictionary of Letter.  Each Letter keeps track of the probability
of going to each other letter.