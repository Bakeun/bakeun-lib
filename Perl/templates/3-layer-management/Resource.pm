
package Resource;

use v5.10;
use strict;
use warnings;
use utf8;

use Data::Dumper;

use Common::IPC;

#Instance Building
sub new
{
	my $class = shift;
	my $self = {
		Config => {
			File => {
				'config_file1' => '/path/to/config1',
				'config_file2' => '/path/to/config2'
			},
			'management_bin' => '/sbin/bin_name',
		}
	};
	bless( $self, $class );

	return $self;
}

#private functions
sub __PRIVATE_FUNCTION{
	#receive parameters
	my $self = shift;

	#parse parameters

	#main routine

	#return result
	return 1;
}

#instance_functions
sub INSTANCE_FUNCTION{
	#receive param.
	my $self = shift;

	#parse param.
	#check param.
	#MAIN ROUTINE
	my $result = Common::IPC::exec( cmd => $self->{ Config }{ management_bin }, args => [ '--comment', 'put options in it!' ]);
	my $exec_info = $result->{ out };
	modify_info( $exec_info );
	#return
	return $result->{ status };
}

1;
