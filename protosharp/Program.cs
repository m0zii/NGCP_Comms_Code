/*
 * Protosharp is a sample C# program using a Protonet session.
 * The periodic node entry messages and two sample messages
 * are displayed in the console.
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using Protonet;
namespace protosharp
{
    /*Hold all state and behavior data in this callback class*/
    public class ProtonetCallbacks
    {
        public ProtonetCallbacks()
        {
        }
        public void OnEnter(
            sbyte link_id, 
            ref Protonet.Header header,
            ref Protonet.Enter rx_msg, 
            Protonet.Node node)
        {
        }
        public void OnExit(
            sbyte link_id,
            ref Protonet.Header header,
            ref Protonet.Exit rx_msg,
            Protonet.Node node)
        {
        }
        public void OnMessage(
            sbyte link_id,
            ref Protonet.Header header,
            ref Protonet.VehicleAuthorizationRequest auth,
            Protonet.Node node)
        {
            Console.WriteLine(auth.handover_node);
        }
        


        public void OnUGVJoystick(
            sbyte link_id, 
            ref Protonet.Header header,
            ref Protonet.UGVJoystick rx_msg, 
            Protonet.Node node)
        {
            Console.WriteLine("Got message");
        }

    }


    class Program
    {
        static void Main(string[] args)
        {
            /*Create a protonet node at specified node id (2)*/
            Protonet.Node UgvNode = new Protonet.Node(2);
            Protonet.Node GcsNode = new Protonet.Node(1);

            /*Construct class to hold all callbacks and behaviors*/
            ProtonetCallbacks UgvCallbacks = new ProtonetCallbacks();

            /*Create a link id variable to reference a created datalink*/
            sbyte link_id = 0;

            /*Register the methods of the callback class with Protonet*/
            UgvNode.RegisterEnterEvent(UgvCallbacks.OnEnter);
            UgvNode.RegisterExitEvent(UgvCallbacks.OnExit);
            UgvNode.RegisterVehicleAuthorizationRequestEvent(UgvCallbacks.OnMessage);

            UgvNode.RegisterUGVJoystickEvent(UgvCallbacks.OnUGVJoystick);

            /*Add a new datalink to the Protonet session and establish an endpoint*/
            UgvNode.AddUDPDatalink(out link_id, 1337, "127.0.0.1");
            UgvNode.EstablishUDPEndpoint(link_id, 1, 1338, "127.0.0.1");

            GcsNode.AddUDPDatalink(out link_id, 1337, "192.168.56.1");
            GcsNode.EstablishUDPEndpoint(link_id, 2, 1337, "192.168.56.2");
            GcsNode.AddSerialDatalink(out link_id, 9600, "COM41");

            GcsNode.SendVehicleAuthorizationRequest(69, 1, 69, 200, 1, 0);
            System.Threading.Thread.Sleep(500);

            //insert 
            //GcsNode.SendVehicleWaypointCommand(69, 0, 69, 30000000, 30000000, 0, 0, 0, 0);
            //GcsNode.SendVehicleWaypointCommand(69, 0, 69, 20000000, 20000000, 0, 0, 1, 0);
            //GcsNode.SendVehicleWaypointCommand(69, 0, 69, 30000000, 30000000, 0, 0, 2, 0);
            //GcsNode.SendVehicleWaypointCommand(69, 0, 69, 50000000, 50000000, 0, 0, 0, 2);
            //GcsNode.SendVehicleWaypointCommand(69, 0, 69, 50000000, 50000000, 0, 0, 0, 2);
            //GcsNode.SendVehicleWaypointCommand(69, 0, 69, 50000000, 50000000, 0, 0, 0, 2);
            
           

            while (true)
            {
                System.Threading.Thread.Sleep(500);
                //GcsNode.SendPayloadBayCommand(69, 1, 1, 1);
                GcsNode.SendVehicleGlobalPosition(0, 1, 101, 30000000, 30000000, 30000000, 300, 102, 120, 120);

            }


        }
    }
}
