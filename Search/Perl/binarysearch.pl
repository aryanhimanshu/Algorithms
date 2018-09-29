#!/usr/bin/perl
use strict;

# forward declarations
sub binary_search;
sub printv;

# Subroutine definition
# Usage: binary_search($needle, @haystack)
# Search for $needle within the sorted array @hastack and return the value of the index (zero-based)
# If not found, returns -1
sub binary_search {
	my @haystack = @_;
	my $needle = shift(@haystack);
	
	my $found = 0;
	my $index = -1;
	my $bottom = 0;
	my $top = scalar(@haystack);
	my $mid;
	my $value;
	
	printv("Searching through an array of ".$top." elements to find ".$needle);

	while (($bottom < $top) & !$found) {
		$mid = int(($top + $bottom)/ 2);
		printv($mid);
		$value = $haystack[$mid];
		printv($value);
		printv("Searching between ".$bottom." and ".$top.", looking at position ".$mid.": ".$value);
		if ($needle == $value) {
			$found = 1;
			$index = $mid;
			printv("Found match for ".$needle." at position ".$index);
		}
		elsif ($needle > $value) {
			$bottom = $mid + 1;
		}
		else {
			$top = $mid - 1;
		}
	}
	if ($index == -1) {
		$value = $haystack[$top];
		printv("Checking the last middle value at ".$top.": ".$value);
		if ($value == $needle) {
			$found = 1;
			$index = $top;
			printv("Found match for ".$needle." at position ".$index);
		} else {
			printv($needle." was not found in the array");
		}
	}
	return $index;
}

# To see the steps of the algorithm as it runs, change this to 1
my $verbose = 1;
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
@array = sort { $a <=> $b } @array;
print "Sorted array to search: ";
foreach (@array) {
	print $_ . " ";
}
print "\n";

# Choose a key to search for
my $key;
print "Please enter key to search for: \n";
$| = 1;	#Flush buffer before looking for input
chomp( $key = <STDIN> );

# Do the search and display the result
my $result = binary_search($key, @array);

if ($result == -1) {
	print "The key was not found in the array.\n"
} else {
	print "The key was found at position ".$result."\n";
}
