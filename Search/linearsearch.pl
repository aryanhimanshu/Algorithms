#!/usr/bin/perl
use strict;

# forward declarations
sub binary_search;
sub printv;

# Subroutine definition
# Usage: linear_search($needle, @haystack)
# Search for $needle within the  array @haystack and return the value of the index (zero-based)
# If not found, returns -1
sub linear_search {
	my @haystack = @_;
	my $needle = shift(@haystack);
	printv($needle);
	printv(@haystack);
	my $found = 0;
	my $len = scalar(@haystack);
	
	my $index = 0;
	my $value;
	foreach $value (@haystack) {
		printv("Checking value at position ".$index."out of ".$len.": ".$value);
		last if ($index == $len);
		if ($value == $needle) {
			$found = 1;
			last;
		}
		$index++;
	}
	return ($found ? $index: -1);
}

# To see the steps of the algorithm as it runs, change this to 1
my $verbose = 0;
sub printv{
	if ($verbose) {
		print "# ";
		print @_;
		print "\n";
		$| = 1;
	}
}

# Usage example
# Generate a random array to search through
my @array;
my $arrsize = rand(20)+10;
while ($arrsize > 0) {
	push(@array, int(rand(10000))-5000);
	$arrsize--;
}
print "Array to search: ";
foreach (@array) {
	print $_ . " ";
}
print "\n";

# Choose a key to search for
my $key;
print "Please enter key to search for: ";
$| = 1;	#Flush buffer before looking for input
chomp( $key = <STDIN> );

# Do the search and display the result
my $result = linear_search($key, @array);

if ($result == -1) {
	print "The key was not found in the array.\n"
} else {
	print "The key was found at position ".$result."\n";
}
