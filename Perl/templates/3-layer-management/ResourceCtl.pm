#!/usr/bin/perl
#=============================================================================
#         FILE: 
#        BRIEF: 
#       AUTHOR: 
#        EMAIL: 
# ORGANIZATION: 
#         DATE: dd/mm/yyyy hh:mm
#     MODIFIED: dd/mm/yyyy hh:mm
#      VERSION: 1.0
#    COPYRIGHT: Copyright(c) 2015 by Gluesys Co., Ltd. All rights reserverd.
#         NOTE: ---
#=============================================================================

package ResourceCtl;

use v5.10;
use strict;
use warnings;
use utf8;

use Data::Dumper;

use ResourceDBI;

#### instance building ####
sub new
{
	my $class = shift;
	my $self = {
		ATTRIBUTE1 => undef,
		ATTRIBUTE2 => undef
	};
	bless( $self, $class );

	return $self;
}

#### Private Function ####
sub __PRIVATE_FUNCTION{
	#receive parameters
	my $self = shift;

	#parse parameters

	#main routine

	#return result
	return 1;
}

sub __get_resource_db
{
	#receive param.
	my $self = shift;

	#get db
	my $dbi = new ResourceDBI;
	$dbi->load();
	my $return_db = $dbi->get();
	if( ref $return_db eq 'HASH' ){ $return_db = [$return_db]; }
	elsif( ! defined $return_db ){ $return_db = []; }

	#return db
	return $return_db;
}

sub __check_existing_entity{
	#recieve param.
	my $self = shift;
	my $target = shift;
	my $db = shift;

	#find the target entity
	my $existing_flag = 0;
	foreach my $entity_finder ( @$db ){
		foreach my $cmp_key ( keys %{ $target } ){
			if( $entity_finder->{ $cmp_key } eq $target->{ $cmp_key } ){
				$existing_flag = 1;
			}else{
				last;
			}
		}
		if( $existing_flag == 1 ){ last; }
	}

	#return
	return $exsisting_flag;
}

sub __check_param{
	#recive param.
	my $self = shift;
	my $params = shift;

	my $aaa = $params->{ aaa };
	my $bbb = $params->{ bbb };
	my $ccc = $params->{ ccc };

	#check integrity of param.

	#$aaa
	if( defined $aaa ){
		#aaa must be not empty
		if( $aaa eq '' ){
			warn "aaa must be not empty";
			return 0;
		}
		#aaa must be less than 3
		if( $aaa < 3 ){
			warn "aaa must be less than 3";
			return 0;
		}
	}else{
		warn "undefined aaa!!";
		return 0;
	}

	#$bbb & $ccc
	if( defined $bbb && defined $ccc ){
		if( $bbb eq '' ){
			warn "bbb must be not empty";
			return 0;
		}else{
			#any routine
		}

		if( $ccc eq '' ){
			warn "ccc must be not empty, too";
			return 0;
		}else{
			#any routine
		}

		if( $bbb < $ccc ){
			warn "That's nono!!";
			return 0;
		}
	}else{
		warn "undefined bbb & ccc!!";
		return 0;
	}

	#return check result
	return 1;
}

#### Instance functions ####
### Reource Control ####
sub INSTANCE_FUNCTION{
	#receive param.
	my $self = shift;

	#parse param.
	#check param.
	#MAIN ROUTINE
	#return
	return 1;
}
*Another_function_name = \&INSTANCE_FUCNTION;

sub function_using_db{

	#receive param.
	my $self = shift;
	my $arguments = shift;

	#parse param.
	my %args;
	if( ref $arguments eq 'HASH' ){
		foreach my $key ( keys %$arguments ){
			$args{ lc $key } = $arguments
		}
	}

	#check param.
	if( ! $self->__check_param( \%args ) ){
		warn "some arguments are missed or invalid";
		return 0;
	}

	#load db
	my $resource_db = $self->__get_resource_db();

	#check the existing one
	my $already_exist = $self->__check_existing_addr(\%args, $resource_db);

	#main routine
	my $result
	if( $already_exist ){
		#any routine
		$result = 0;
	}else{
		#any routine
		$result = 1;
	}

	#return
	return $return;
}

1;
