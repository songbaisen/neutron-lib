.. -*- rst -*-

=================================
Security groups (security-groups)
=================================

Lists, creates, shows information for, updates, and deletes
security groups.

List security groups
====================

.. rest_method::  GET /v2.0/security-groups

Lists OpenStack Networking security groups to which the project has access.

The response is an array of ``security_group`` objects which contains a list of
``security_group_rules`` objects.

Use the ``fields`` query parameter to control which fields are
returned in the response body. Additionally, you can filter results
by using query string parameters. For information, see `Filtering
and Column Selection <https://wiki.openstack.org/wiki/Neutron/APIv2
-specification#Filtering_and_Column_Selection>`__.

Normal response codes: 200

Error response codes: 401

Request
-------

.. rest_parameters:: parameters.yaml

   - fields: fields

Response Parameters
-------------------

.. rest_parameters:: parameters.yaml

   - security_groups: security_groups-obj
   - id: security_group-id
   - tenant_id: project_id
   - project_id: project_id
   - revision_number: revision_number
   - name: name
   - description: description
   - security_group_rules: security_group_rules

Response Example
----------------

.. literalinclude:: samples/security-groups/security-groups-list-response.json
   :language: javascript

Create security group
=====================

.. rest_method::  POST /v2.0/security-groups

Creates an OpenStack Networking security group.

This operation creates a security group with default security group
rules for the IPv4 and IPv6 ether types.

Normal response codes: 201

Error response codes: 400, 401, 409

Request
-------

.. rest_parameters:: parameters.yaml

   - security_group: security_group
   - tenant_id: project_id
   - project_id: project_id
   - description: description-request
   - name: name

Request Example
---------------

.. literalinclude:: samples/security-groups/security-group-create-request.json
   :language: javascript

Response Parameters
-------------------

.. rest_parameters:: parameters.yaml

   - security_group: security_group
   - id: security_group-id
   - tenant_id: project_id
   - project_id: project_id
   - revision_number: revision_number
   - name: name
   - description: description
   - security_group_rules: security_group_rules

Response Example
----------------

.. literalinclude:: samples/security-groups/security-group-create-response.json
   :language: javascript

Show security group
===================

.. rest_method::  GET /v2.0/security-groups/{security_group_id}

Shows details for a security group.

The associated security group rules are contained in the response.

Normal response codes: 200

Error response codes: 401, 404

Request
-------

.. rest_parameters:: parameters.yaml

   - security_group_id: security_group-id-path
   - verbose: verbose
   - fields: fields

Request Example
---------------

.. literalinclude:: samples/security-groups/security-group-show-request-json-http.txt
   :language: javascript

Response Parameters
-------------------

.. rest_parameters:: parameters.yaml

   - security_group: security_group
   - id: security_group-id
   - tenant_id: project_id
   - project_id: project_id
   - revision_number: revision_number
   - name: name
   - description: description
   - security_group_rules: security_group_rules

Response Example
----------------

.. literalinclude:: samples/security-groups/security-group-show-response.json
   :language: javascript

Update security group
=====================

.. rest_method::  PUT /v2.0/security-groups/{security_group_id}

Updates a security group.

Normal response codes: 200

Error response codes: 400, 401, 403, 404, 412

Request
-------

.. rest_parameters:: parameters.yaml

   - security_group_id: security_group-id-path
   - security_group: security_group
   - description: description-request
   - name: name

Request Example
---------------

.. literalinclude:: samples/security-groups/security-group-update-request.json
   :language: javascript

Response Parameters
-------------------

.. rest_parameters:: parameters.yaml

   - security_group: security_group
   - id: security_group-id
   - tenant_id: project_id
   - project_id: project_id
   - revision_number: revision_number
   - name: name
   - description: description
   - security_group_rules: security_group_rules

Response Example
----------------

.. literalinclude:: samples/security-groups/security-group-update-response.json
   :language: javascript

Delete security group
=====================

.. rest_method::  DELETE /v2.0/security-groups/{security_group_id}

Deletes an OpenStack Networking security group.

This operation deletes an OpenStack Networking security group and
its associated security group rules, provided that a port is not
associated with the security group. If a port is associated with the security
group 409 (Conflict) is returned.

This operation does not require a request body. This operation does
not return a response body.

Normal response codes: 204

Error response codes: 401, 404, 409, 412

Request
-------

.. rest_parameters:: parameters.yaml

   - security_group_id: security_group-id-path

Request Example
---------------

.. literalinclude:: samples/security-groups/security-group-delete-request-json-http.txt
   :language: javascript

Response
--------

There is no body content for the response of a successful DELETE request.
