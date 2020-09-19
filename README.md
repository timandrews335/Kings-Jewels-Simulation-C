# Kings-Jewels-Simulation-C

This is an implementation of the "King's Jewels Problem" detailed at the following blog post:  http://emptypipes.org/2015/10/21/kings-jewels/

A simpler way to think of the problem would be "how many partners should I date before deciding to marry the next one, who was as good as or better than the best that I have dated so far?"

Anyways, I have written this application in Visual Basic 2013, R and now C.  The purpose is simply an exercise to keep my 3GL skills up to date since I spend all day working on databases these days.

The C version is very fast.  This probably most related to the fact that it has no graphical interface as does my VB version, nor does it render charts as does my R version.

Currently, to use this application, compile and run it.  You will be prompted for the number of simulations that you wish to run - I typically choose about one thousand.   You will then be prompted to enter the number of jewels that you will look at and discard before making your selection.  The number should be between 1 and 9, since the bag of jewels will always contain ten jewels.
