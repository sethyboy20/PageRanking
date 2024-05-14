## Page Ranking Algorithm
A program that uses a simplified page rank algorithm to calculate and display a ranking of given webpages as a graphical representation.

## Usage
Run ```make run``` to build and start the program.

Input should be formatted as this, where p = # of power iterations and n = # of links:

```console
n p
<source URL> <destination URL> (line 1)
...
<source URL> <destination URL> (line n)
```

Example input:
```console
4 2
google.com maps.com
ufl.edu google.com
gmail.com maps.com
maps.com facebook.com
```

Run ```make test``` to perform the program's unit tests.
