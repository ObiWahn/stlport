// -*- C++ -*- Time-stamp: <08/10/27 08:29:53 ptr>

/*
 * Copyright (c) 2008
 * Petr Ovtchenkov
 *
 * Licensed under the Academic Free License Version 3.0
 *
 */

#include <exam/suite.h>

#include <misc/opts.h>
#include <string>
#include <sstream>

#include "vector_test.h"
#include "numerics.h"

// ------------
#include "cppunit_proxy.h"
#include "file_reporter.h"
#include "cppunit_timer.h"

#include "stdio.h"

  int TestCase::m_numErrors = 0;
  int TestCase::m_numTests = 0;

  TestCase *TestCase::m_root = 0;
  Reporter *TestCase::m_reporter = 0;

  void TestCase::registerTestCase(TestCase *in_testCase) {
    in_testCase->m_next = m_root;
    m_root = in_testCase;
  }

  int TestCase::run(Reporter *in_reporter, const char *in_testName, bool invert) {
    TestCase::m_reporter = in_reporter;

    m_numErrors = 0;
    m_numTests = 0;

    TestCase *tmp = m_root;
    while (tmp != 0) {
      tmp->myRun(in_testName, invert);
      tmp = tmp->m_next;
    }
    return m_numErrors;
  }

int test_main() {
  CPPUNIT_NS::Reporter* reporter = new FileReporter( stdout, false );

  int num_errors = CPPUNIT_NS::TestCase::run(reporter, "" );

  reporter->printSummary();
  delete reporter;

  return num_errors;
}

// ------------

int main( int argc, const char** argv )
{
  Opts opts;

  opts.description( "test suite for 'sockios' framework" );
  opts.usage( "[options]" );

  opts << option<bool>( "print this help message", 'h', "help" )
       << option<bool>( "list all test cases", 'l', "list" )
       << option<std::string>( "run tests by number", 'r', "run" )["0"]
       << option<bool>( "print status of tests within test suite", 'v', "verbose" )
       << option<bool>(  "trace checks", 't', "trace" );

  try {
    opts.parse( argc, argv );
  }
  catch (...) {
    opts.help( std::cerr );
    return 1;
  }

  if ( opts.is_set( 'h' ) ) {
    opts.help( std::cerr );
    return 0;
  }

  exam::test_suite t( "STLport test" );

  vector_test vec_test;

  exam::test_suite::test_case_type vec_tc[16];

  t.add( &vector_test::vec_test_1, vec_test, "vec_test_1" );
  t.add( &vector_test::vec_test_2, vec_test, "vec_test_2" );
  t.add( &vector_test::vec_test_3, vec_test, "vec_test_3" );
  t.add( &vector_test::vec_test_4, vec_test, "vec_test_4" );
  t.add( &vector_test::vec_test_5, vec_test, "vec_test_5" );
  t.add( &vector_test::vec_test_6, vec_test, "vec_test_6" );
  t.add( &vector_test::vec_test_7, vec_test, "vec_test_7" );
  t.add( &vector_test::capacity, vec_test, "vector capacity" );
  t.add( &vector_test::at, vec_test, "vector at" );
  t.add( &vector_test::pointer, vec_test, "vector pointer" );
  t.add( &vector_test::auto_ref, vec_test, "vector auto_ref" );
  t.add( &vector_test::allocator_with_state, vec_test, "vector allocator_with_state" );
  vec_tc[12] = t.add( &vector_test::iterators, vec_test, "vector iterators" );
  t.add( &vector_test::optimizations_check, vec_test, "vector optimizations_check" );
  t.add( &vector_test::assign_check, vec_test, "vector assign_check" );
  t.add( &vector_test::ebo, vec_test, "vector ebo" );

  numerics num_test;

  exam::test_suite::test_case_type num_tc[6];

  t.add( &numerics::accum2, num_test, "accumulate, non-default functor",
    num_tc[0] = t.add( &numerics::accum1, num_test, "accumulate" ) );

  num_tc[1] = vec_tc[12];
  t.add( &numerics::times, num_test, "accumulate, multiplies<int> functor", num_tc, num_tc + 2 );

  num_tc[1] = t.add( &numerics::partsum0, num_test, "partial summ, raw array" );
  num_tc[2] = vec_tc[12];
  num_tc[2] = t.add( &numerics::partsum1, num_test, "partial summ, vector", num_tc + 1, num_tc + 3 );
  num_tc[3] = vec_tc[12];
  t.add( &numerics::partsum2, num_test, "partial summ, multiplies<int> functor", num_tc + 2, num_tc + 4 );

  num_tc[3] = t.add( &numerics::innprod0, num_test, "inner product, raw array" );
  num_tc[4] = vec_tc[12];
  num_tc[4] = t.add( &numerics::innprod1, num_test, "inner product, vector", num_tc + 3, num_tc + 5 );
  num_tc[5] = vec_tc[12];
  t.add( &numerics::innprod2, num_test, "inner product, userdefined functors", num_tc + 4, num_tc + 6 );

  if ( opts.is_set( 'l' ) ) {
    t.print_graph( std::cerr );
    return 0;
  }

  if ( opts.is_set( 'v' ) ) {
    t.flags( t.flags() | exam::base_logger::verbose );
  }

  if ( opts.is_set( 't' ) ) {
    t.flags( t.flags() | exam::base_logger::trace );
  }

  if ( opts.is_set( 'r' ) ) {
    std::stringstream ss( opts.get<std::string>( 'r' ) );
    int n;
    while ( ss >> n ) {
      t.single( n );
    }

    return 0;
  }

  return t.girdle() + test_main();
}