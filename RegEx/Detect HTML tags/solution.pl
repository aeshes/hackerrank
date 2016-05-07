# Task
# Given NN lines of HTML, find the tag names (ignore any attributes) and print them
# as a single line of lexicographically ordered semicolon-separated values
# (e.g.: tag1;tag2;tag3tag1;tag2;tag3).

use strict;

my @tags = ();
while (<>) {
        push @tags, /<\s*(\w+)/g;
}

my %hash = map {$_ => 1} @tags;
print join ";", sort keys %hash;