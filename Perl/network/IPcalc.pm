package IPcalc;

use v5.10;
use strict;
use warnings;
use utf8;

#change xx.xx.xx.xx type address to deximal number
sub addr_to_dex{ 
	my $addr = shift;

	my $deximal_addr = 0;
	my @addr_split = split /\./, $addr;
	for( my $class = 0;$class < 4; $class++ ){
		$deximal_addr += ( $addr_split[3-$class] << ( 8 * $class ) );
	}

	return $deximal_addr;
}
*dex = \&addr_to_dex;

#change deximal number to xx.xx.xx.xx type address
sub dex_to_addr{
	my $deximal_addr = shift;

	my @addr_split = (
		( $deximal_addr & 255*256*256*256 ) >> 24,
		( $deximal_addr & 255*256*256 ) >> 16,
		( $deximal_addr & 255*256 ) >> 8,
		( $deximal_addr & 255 ) >> 0
	);
	my $addr = join '.', @addr_split;

	return $addr;
}
*addr = \&dex_to_addr;

#change xx.xx.xx.xx type netmask to 1~32 number
sub get_maskbit{
	my $str_netmask = shift;

	my $dex_netmask = addr_to_dex( $str_netmask );
	my $maskbit = 32;
	while( $maskbit > 0 ){
		if( $dex_netmask%2 ){
			last;
		}else{
			$dex_netmask =  $dex_netmask / 2;
			$maskbit--;
		}
	}

	return $maskbit;
}
*maskbit = \&get_maskbit;

1;
