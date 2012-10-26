/*
 * A sample test case which can be used as a template.
 */
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../src/node.h"
#include "../src/forest.h"

class TestNode : public CppUnit::TestCase {

  CPPUNIT_TEST_SUITE( TestNode );

  CPPUNIT_TEST( testGettersAndSetters );
  CPPUNIT_TEST( testIsFake );
  CPPUNIT_TEST( testIsUltimateRoot );
  CPPUNIT_TEST( testIsRoot );

  CPPUNIT_TEST_SUITE_END();

 private:
  Forest *forest;
  ConstantGenerator *rg;

 public:
  void setUp() {
    rg = new ConstantGenerator();
    forest = new Forest(Model(0), rg);
    forest->createExampleTree();
  }

  void tearDown() {
    delete forest;
  }

  void testGettersAndSetters() {
    Node node1, node2;

    //height
    node1.set_height(1);
    CPPUNIT_ASSERT( node1.height() == 1 );

    //parent
    node2.set_parent(&node1);
    CPPUNIT_ASSERT( node2.parent()->height() == 1 );

    //Children
    node2.set_higher_child(&node1);
    CPPUNIT_ASSERT( node2.higher_child()->height() == 1 );
    node2.set_lower_child(&node1);
    CPPUNIT_ASSERT( node2.lower_child()->height() == 1 );

    //active
    node1.set_active(true);
    node2.set_active(false);
    CPPUNIT_ASSERT( node1.active() && !node2.active() );
    node1.deactivate();
    node2.activate();
    CPPUNIT_ASSERT( (!node1.active()) && node2.active() );
  }

  void testIsRoot(){
    CPPUNIT_ASSERT( !forest->nodes()[0]->is_root() );
    CPPUNIT_ASSERT( !forest->nodes()[1]->is_root() );
    CPPUNIT_ASSERT( !forest->nodes()[2]->is_root() );
    CPPUNIT_ASSERT( !forest->nodes()[3]->is_root() );
    CPPUNIT_ASSERT( !forest->nodes()[4]->is_root() );
    CPPUNIT_ASSERT( !forest->nodes()[5]->is_root() );
    CPPUNIT_ASSERT( forest->nodes()[6]->is_root() );
    CPPUNIT_ASSERT( forest->nodes()[7]->is_root() );
  }

  void testIsUltimateRoot(){
    CPPUNIT_ASSERT( !forest->nodes()[0]->is_ultimate_root() );
    CPPUNIT_ASSERT( !forest->nodes()[1]->is_ultimate_root() );
    CPPUNIT_ASSERT( !forest->nodes()[2]->is_ultimate_root() );
    CPPUNIT_ASSERT( !forest->nodes()[3]->is_ultimate_root() );
    CPPUNIT_ASSERT( !forest->nodes()[4]->is_ultimate_root() );
    CPPUNIT_ASSERT( !forest->nodes()[5]->is_ultimate_root() );
    CPPUNIT_ASSERT( !forest->nodes()[6]->is_ultimate_root() );
    CPPUNIT_ASSERT( forest->nodes()[7]->is_ultimate_root() );
  }

  void testIsFake(){
    CPPUNIT_ASSERT( !forest->nodes()[0]->is_fake() );
    CPPUNIT_ASSERT( !forest->nodes()[1]->is_fake() );
    CPPUNIT_ASSERT( !forest->nodes()[2]->is_fake() );
    CPPUNIT_ASSERT( !forest->nodes()[3]->is_fake() );
    CPPUNIT_ASSERT( !forest->nodes()[4]->is_fake() );
    CPPUNIT_ASSERT( !forest->nodes()[5]->is_fake() );
    CPPUNIT_ASSERT( !forest->nodes()[6]->is_fake() );
    CPPUNIT_ASSERT( forest->nodes()[7]->is_fake() );
  }

};

CPPUNIT_TEST_SUITE_REGISTRATION( TestNode );
