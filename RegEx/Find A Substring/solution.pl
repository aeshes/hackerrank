#!/usr/bin/perl
use strict;

chomp(my $lines_count = <>);	# read the number of centences
my @words;
for (1..$lines_count)
{
    	my $line = <>;
	push @words, split /\s+/, $line;
}

my $pattern_count = <>;
for (1..$pattern_count)
{
    	chomp(my $input = <>);
	my $result = 0;
	foreach (@words)
	{
		if (/\w+$input\w+/)
		{
			$result++;
		}
	}
	print $result, "\n";
}