package IPcalc;

use v5.10;
use strict;
use warnings;
use utf8;

#change xx.xx.xx.xx type address to deximal number
sub addr_to_dec{ 
	my $addr = shift;

	my $decimal_addr = 0;
	my @addr_split = split /\./, $addr;
	for( my $class = 0;$class < 4; $class++ ){
		$decimal_addr += ( $addr_split[3-$class] << ( 8 * $class ) );
	}

	return $decimal_addr;
}
*dec = \&addr_to_dec;

#change decimal number to xx.xx.xx.xx type address
sub dec_to_addr{
	my $decimal_addr = shift;

	my @addr_split = (
		( $decimal_addr & 255*256*256*256 ) >> 24,
		( $decimal_addr & 255*256*256 ) >> 16,
		( $decimal_addr & 255*256 ) >> 8,
		( $decimal_addr & 255 ) >> 0
	);
	my $addr = join '.', @addr_split;

	return $addr;
}
*addr = \&dec_to_addr;

#change xx.xx.xx.xx type netmask to 1~32 number
sub get_maskbit{
	my $str_netmask = shift;

	my $dec_netmask = addr_to_dec( $str_netmask );
	my $maskbit = 32;
	while( $maskbit > 0 ){
		if( $dec_netmask%2 ){
			last;
		}else{
			$dec_netmask =  $dec_netmask / 2;
			$maskbit--;
		}
	}

	return $maskbit;
}
*maskbit = \&get_maskbit;

1;
