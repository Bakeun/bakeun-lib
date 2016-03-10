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

package ResourceDBI;

use v5.10;
use strict;
use warnings;
use utf8;

use Data::Dumper;

use Resource; #manage Resource directly
#use DBrwMODULE;

#### instance building ####
sub new
{
	my $class = shift;
	my $self = {
		RESOURCE => undef,
		DBI => undef,
		ATTRIBUTE1 => undef,
		ATTRIBUTE2 => undef,
	};
	bless( $self, $class );

	#$self->{ DBI } = new DBrwMODULE;

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

sub load_resource
{
	#receive param.
	#parse param.
	my $self = shift;

	#read db
	my $data; #from DataBase
	#$data = $self->{ DBI }->get();

	#put db into RESOURCE
	$self->{ RESOURCE } = $data;

	#return
	return 1;
}
*load = \&load_resource;

sub get_resource
{
	#receive param.
	#parse param.
	my $self = shift;

	#return RESOURCE
	return $self->{ RESOURCE };
}
*get = \&get_resource;

sub apply_resource
{
	my $self = shift;

	#apply $self->{ RESOURCE } to DataBase

	#return
	return 1;
}
*apply = \&apply_resource;

sub create_resource
{
	#recieve param.
	#parse param.
	my $self = shift;
	my $edit = shift;
	#print Dumper $edit;

	#read db
	$self->load_resource();
	my $data = $self->get_resource();

	if( ! defined $data ){
		$data = ();
	}

	#create str_addr
	push @$data, $edit;
	#print Dumper $data;


	#db commit
	$self->{ RESOURCE } = $data;
	my $return = $self->apply_resource();

	#return
	return $return;
}
*create = \&create_resource;

sub modify_resource
{
	#recieve param.
	#parse param.
	#read db
	#update db
	#db commit
	#return
	return 1;
}
*modify = \&modify_resource;

sub remove_resource
{
	#recieve param.
	#parse param.
	my $self = shift;
	my $edit = shift;
	#print Dumper $edit;

	#read db
	$self->load_resource();
	my $data = $self->get_resource();

	#delete svc_addr
	my @tmp_arr;
	my $find_flag = 0;
	foreach my $edit_finder ( @$data ){
		#print Dumper $edit_finder;
		foreach my $cmp_key ( keys %{ $edit } ){
			if( $edit_finder->{ $cmp_key } eq $edit->{ $cmp_key } ){
				$find_flag = 1;
			}else{
				$find_flag = 0;
				last;
			}
		}
		if( $find_flag == 0 ){
			push @tmp_arr, $edit_finder;
		}
	}
	$data = \@tmp_arr;

	#db commit
	$self->{ RESOURCE } = $data;
	my $return = $self->apply_resource();

	#return
	return $return;
}
*remove = \&remove_resource;

1;
